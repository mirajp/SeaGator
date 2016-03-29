#Andrew Koe
import Tkinter as tk
from subprocess import Popen, PIPE
import wnck , gtk,re

class Keyboard:
    def __init__(self):
        top = tk.Tk()
        top.title("Seagator Keyboard")
        button_list = ['q','w','e','r','t','y','u','i','o','p','<-',
                        'a','s','d','f','g','h','j','k','l',
                        'z','x','c','v','b','n','m'
                        ,' Space ']

        entry = tk.Entry(top,width = 84)
        entry.grid(row=1, columnspan=15)

        r = 2
        c = 0
        for b in button_list:
            rel = 'groove'
            command = lambda x=b: self.keypress("key " + x+"'")
            if b != " Space ":
                tk.Button(top, text = b, width = 10,height= 5, relief = rel, command = command).grid(row = r, column = c)
            elif b == " Space ":
                tk.Button(top, text = b, width = 30,height = 5, relief = rel, command = command).grid(row = 5, columnspan = 10)
            c+=1
            if c > 10 and r == 2:
                c = 0
                r+=1
            if c > 8 and r == 3:
                c = 0
                r+=1
        top.attributes("-topmost",True)        
        top.mainloop()
    
    def keypress(self,sequence):
        #get the active window
        screen = wnck.screen_get_default()
        screen.force_update()
        while gtk.events_pending():
            gtk.main_iteration()
        window_list = screen.get_windows()
        #active_window = screen.get_active_window().get_name()
        #active the second to last window unless it is the Seagator keyboard, then activate last opened
        if not re.search("Sea",window_list[-2].get_name()):
            window_list[-2].activate(0)
        else:
            window_list[-1].activate(0)

       # for w in window_list
       #     print w.get_name()
        
        if re.search("<-",sequence):
            sequence = "key BackSpace'"
        p = Popen(['xte'], stdin=PIPE)
        p.communicate(input=sequence)
        for w in window_list:
            if re.search("Sea",w.get_name()):
                w.activate(0) # reactivate the keyboard

        screen.force_update()
Keyboard()
