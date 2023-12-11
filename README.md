# BML-Bluetooth_Module_Library_for_HC06

 it's library for HC-06 bluetooth module library, which giva you a chance to configure your bt module.
 
## Begin with library

After adding library to arduino IDE, you must add library to your sketch

`#include <BML.h>`

Next you must create object. If you want use hardware library it should looks that:

`BML bml(Serial)`

If you want use software serial you must first add library:

`#include <SoftwareSerial.h>`

and create object:

`SoftwareSerial softS(RXPin, TXPin);`

Where *RXPin* and *TXPin* are pins which are used to connect bt module. Next you can create the library object.

`BML bml(softS);`

## Available methods

`void waitTime(unsigned int time)`

Set default value for *time* in other methods.

`bool convertBaudrate(unsigned long baudRate, unsigned int time);`

It available to set baudrate in bt module. In arduino you must do it manualy. You can set consecutive baudrate:
- 1200bps
- 2400bps
- 4800bps
- 9600bps
- 19200bps
- 38400bps
- 57600bps
- 115200bps
It return *true* if get respond, that baudrate was changed.

`bool setDeviceName(String deviceName, unsigned int time);`

`bool setPin(String Pin, unsigned int time);`

`String deviceVersion(unsigned int time);`

Return information about version of bt module.

`void reset();`

Reset bt module.

`bool untilPlug(unsigned int time);`

Until arduino doesn't get respond, that bt module is connected or blow over *time*, it waits.

