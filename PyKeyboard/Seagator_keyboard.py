#Andrew Koe
import Tkinter as tk
from subprocess import Popen, PIPE
import wnck , gtk,re
import time
import pyautogui
import word

shift_pressed = False
buf = []

sug1 = None
sug2 = None
sug3 = None
class Keyboard:
    def __init__(self):
        top = tk.Tk()
	global sug1
	global sug2
	global sug3
        top.title("Seagator Keyboard")
        button_list = ['q','w','e','r','t','y','u','i','o','p','<-',
                        'a','s','d','f','g','h','j','k','l',' Enter ',
                        'z','x','c','v','b','n','m',u'\u2191'
                        ,' Space ']

#	sug4 = tk.Button(top,width=14,height=3)
#	sug4.grid(row=1, columnspan=14)

#	sug5 = tk.Button(top,width=10,height=3)
#	sug5.grid(row=1, columnspan=18)

        r = 2
        c = 0
        for b in button_list:	 
	    sug1 = tk.Button(top,text="",width = 14,height = 2,font = ("Helvetica",15), relief = 'groove',command=lambda: self.put_suggest(sug1['text']))
            sug1.grid(row=1,columnspan=2)
	    

            sug2 = tk.Button(top,text="",width=14,height=2, font = ("Helvetica",15), relief = 'groove',command=lambda: self.put_suggest(sug2['text']))
            sug2.grid(row=1,columnspan=6)
	    
            sug3 = tk.Button(top,text="",width=14,height=2,font = ("Helvetica",15), relief = 'groove',command=lambda: self.put_suggest(sug3['text']))
            sug3.grid(row=1,columnspan=10)
	    

            rel = 'groove'
            command = lambda x=b: self.keypress("key " + x+"'")
            if b != " Space ":
                tk.Button(top, text = b, width = 7,height= 3,font = ("Helvetica",15), relief = rel, command = command).grid(row = r, column = c)
            elif b == " Space ":
                tk.Button(top, text = b, width = 30,height = 3,font=("Helvetica",15), relief = rel, command = command).grid(row = 5, columnspan = 9)
            c += 1
            if c > 10 and r == 2:
                c = 0
                r+=1
            if c > 9 and r == 3:
                c = 0
                r+=1
        top.attributes("-topmost",True)        
        top.mainloop()

    def put_suggest(self,txt):
	 #get the active window
        global buf
        screen = wnck.screen_get_default()
        screen.force_update()
        while gtk.events_pending():
            gtk.main_iteration()
        window_list = screen.get_windows()
        #active_window = screen.get_active_window().get_name()
        #active the second to last window unless it is the Seagator keyboard, then activate last opened
        """
	if not re.search("Seagator Keyboard",window_list[-2].get_name()):
            window_list[-2].activate(int(time.time()))
        else:
            window_list[-1].activate(int(time.time()))
        """

        for w in window_list:
            if re.search("scratchpaper.txt",w.get_name()):
                w.activate(int(time.time()))

	time.sleep(0.1)

	cnt = 0
	while cnt < len(buf):
	    pyautogui.press('backspace')
	    cnt += 1
	pyautogui.typewrite(txt + " ")
	for w in window_list:
	    if re.search("Seagator Keyboard",w.get_name()):
		w.activate(int(time.time()))	
	
 	sug1['text'] = ""
        sug2['text'] = ""
        sug3['text'] = ""
	word.suggestions = []
	buf = []
    
    def keypress(self,sequence):
	global buf
        #get the active window
        global shift_pressed
        screen = wnck.screen_get_default()
	screen.force_update()

        while gtk.events_pending():
            gtk.main_iteration()
        window_list = screen.get_windows()
        #active_window = screen.get_active_window().get_name()
        #active the second to last window unless it is the Seagator keyboard, then activate last opened
        """
	if not re.search("Seagator Keyboard",window_list[-2].get_name()):
            window_list[-2].activate(int(time.time()))
        else:
            window_list[-1].activate(int(time.time()))
	time.sleep(0.1)
	"""
	for w in window_list:
	    if re.search("scratchpaper.txt",w.get_name()):
		w.activate(int(time.time()))
	time.sleep(0.1)
       # for w in window_list
       #     print w.get_name()
        if shift_pressed == True:
            sequence = '''keydown Shift_L\n''' + sequence[:-1] + '''\nkeyup Shift_L\n'''
            shift_pressed = not shift_pressed
 
        if re.search("<-",sequence):
            sequence = "key BackSpace'"
	    try:
	    	buf.pop()
	    except IndexError:
		pass
        elif re.search("Enter",sequence):
            sequence = "key Return'"
	    buf = []
	    word.suggestions = []
        elif re.search(u'\u2191',sequence):
            #global shift_pressed
            shift_pressed = not shift_pressed
            return
	elif re.search("Space",sequence):
	    buf = []
	    word.suggestions = []
	    sug1['text'] = ""
            sug2['text'] = ""
            sug3['text'] = ""
	else:
	    if not re.search("keydown Shift",sequence):
	    	buf.append(sequence[4])
	    else:
		buf.append(sequence[20])


        p = Popen(['xte'], stdin=PIPE)
        p.communicate(input=sequence)
        for w in window_list:
            if re.search("Sea",w.get_name()):
                w.activate(int(time.time())) # reactivate the keyboard

	if len(buf) > 1:
	    root.search("".join(buf))
	    try:
	    	sug1['text'] = word.suggestions[0]
	    	sug2['text'] = word.suggestions[1]
	    	sug3['text'] = word.suggestions[2]
	    except IndexError:
		pass
	    word.suggestions = []
        screen.force_update()


root = word.fileparse()
Keyboard()
