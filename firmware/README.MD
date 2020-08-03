Firmware files are from here:
* https://github.com/arduino/ArduinoCore-avr/tree/master/firmwares/atmegaxxu2
* https://github.com/coopermaa/USBKeyboard/tree/master/firmware
* https://github.com/trusktr/arduino-lufa-keyboard


Steps to program:
* Short out the reset pin and ground on the atmega16u2 ICSP header.
* Run: `./dfu-programmer atmega16u2 erase`
* Run: `./dfu-programmer atmega16u2 flash ~/projects/arduino/Arduino-keyboard-0.3.hex`

