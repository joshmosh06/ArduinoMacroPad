# ArduinoMacroPad
This is the implementation of a 4 Key keyboard that uses an Arduino uno and the Standard HID keyboard driver for USB. This a acheved by using the FILP program from AMTEL to flash the UNO's 16megaU2 USB inferface chip. 
Pins 3456 are keys.
The code has a few keys from the USB HID Spec sheet, however these keys can be binded to any key using the provided hex values in the data sheet.
Pins 7, 8, 9, 10, 11, 12 are used by a LCD 1602A that is used to display debug info while the keyboard is running as when the new firmware is flashed on to the 16megaU2 the ardiuno can no longer be accesed via the Arduino application.

The code also has a DHT thermometer at pin 13 and displays the temp to the screens first line.
