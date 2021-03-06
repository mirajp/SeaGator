#!/usr/bin/env python
"""Make the X cursor wrap-around.

Adapted from http://appdb.winehq.org/objectManager.php?sClass=version&iId=12599
to work around lack of relative mouse movement http://wiki.winehq.org/Bug6971
for Thief: Dark Shadows (and possibly others)

This version is a little kinder to your CPU than the shell script with
the busy-loop that starts a new process for every pointer query.
"""
from ctypes import cdll, c_int, c_voidp, byref
import time

xlib = cdll.LoadLibrary('libX11.so')

# Maximum screen width and height
MAX_X = 1280
MAX_Y = 1024

# Number of seconds to sleep between polling mouse position.
SLEEPTIME = 0.05

def _main(display):
    root = xlib.XDefaultRootWindow(display)
    mousex = c_int()
    mousey = c_int()
    # pointer for unused return values 
    unused_int = c_int()
    # likewise, querypointer wants a window pointer to write to.  We don't
    # really want to create a new window, but this was the shortest way I
    # could think of to get the memory allocated.
    tmp_win = c_voidp(xlib.XCreateSimpleWindow(display, root, 0, 0, 1, 1,
                                               0, 0, 0))
    def resetMouse(x, y):
        xlib.XWarpPointer(display,None,root,0,0,0,0,x,y)

    def getMouse():
        xlib.XQueryPointer(display, root,
                           byref(tmp_win), byref(tmp_win),
                           byref(mousex), byref(mousey),
                           byref(unused_int),
                           byref(unused_int),
                           byref(unused_int))

    while 1:
        getMouse()
	time.sleep(1)
	resetMouse(x=10,y=10)
	getMouse()
	time.sleep(1)
	resetMouse(x=30,y=30)
	getMouse()
	time.sleep(1)
	resetMouse(x=60,y=60)
	
	"""
        if (mousex.value < 2):
            resetMouse(x=MAX_X-2, y = mousey.value)
        elif (mousex.value > (MAX_X-2)):
            resetMouse(x=2, y=mousey.value)
	"""
        #time.sleep(SLEEPTIME)


def main():
    try:
        display = xlib.XOpenDisplay(None)
        _main(display)
    finally:
        xlib.XCloseDisplay(display)


if __name__ == '__main__':
    main()
