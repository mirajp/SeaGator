
import Tkinter as tk
from subprocess import Popen, PIPE
import wnck


top = tk.Tk()
top.title("On Screen Keyboard")

def click(key):
    if key == "<-":
        entry2 = entry.get()
        pos = entry2.find("")
        pos2 = entry2[pos:]
        entry.delete(len(pos2)-1, tk.END)
    elif key == " Space ":
        entry.insert(tk.END, ' ')
    else:
        entry.insert(tk.END,key)

def keypress(sequence):
    p = Popen(['xte'], stdin=PIPE)
    p.communicate(input=sequence)


def target_window():
	pass	
button_list = [
'q','w','e','r','t','y','u','i','o','p','<-',
'a','s','d','f','g','h','j','k','l',
'z','x','c','v','b','n','m'
,' Space ']

entry = tk.Entry(top, width = 84)
entry.grid(row = 1, columnspan = 15)

r = 2
c = 0
for b in button_list:
    rel = 'groove'
    command = lambda x=b: keypress("key " + x+"'")
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
    
top.mainloop()

