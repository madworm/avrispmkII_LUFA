Please get this version:

http://code.google.com/p/lufa-lib/source/detail?r=2226


------


This patch is against 'LUFA-120219.zip'


The situation is as follows:

The avrispmkII clone runs on linux with avrdude 5.11, no problems.
On windows it runs with AvrStudio.

However to make it run with avrdude + libusb on windows one currently
has to recompile the firmware (change of USB endpoint number).

standard:

#define AVRISP_DATA_IN_EPNUM 2

vs. libusb:

#define AVRISP_DATA_IN_EPNUM 3


As said before avrdude on linux doesn't seem to care.

Having to recompile the firmware is pretty annoying, given that
the used at90usb162 has still enough FLASH space left for some changes.

This modification does just that.

It assumes that your avrispmkII clone has a reset button and another
jumper that has to be set to trigger the bootloader.

To activate the bootloader short this jumper and press the reset button.
Then use 'flash.sh' to upload the new firmware (requires 'dfu-programmer').

Then disconnect and reconnect power.

The device will behave exactly the same as before, it will enumerate with
endpoints (2,2) and will work with avrdude on linux + AvrStudio on windows.
The latter requires the Jungo driver to be installed properly.

If you press the reset button, it will change its endpoint settings to (2,3).
It will still work with avrdude on linux, but NOT with AvrStudio anymore.
However in this mode it will work with avrdude on windows if the libusb drivers
are installed!

Press the reset button again and it is back to default. The same is true
if power is removed.

Have fun!


How to build (linux) / use on windows:

http://www.youtube.com/watch?v=tORRNU5QLpc
http://www.youtube.com/watch?v=1IHecxN8TBQ

