import uinput
import time
import evdev
device = uinput.Device([
        uinput.BTN_LEFT,
        uinput.BTN_RIGHT,
        uinput.REL_X,
        uinput.REL_Y,
	uinput.ABS_X,
	uinput.ABS_Y
        ])

for i in range(20):
    time.sleep(0.01)
    device.emit(uinput.ABS_X, 0)
    device.emit(uinput.ABS_Y, 0)
