
#ifndef BML_h
#define BML_h
#include <arduino.h>
#include <SoftwareSerial.h>

/*
 *1 set to 1200bps
  2 set to 2400bps
  3 set to 4800bps
  4 set to 9600bps (Default)
  5 set to 19200bps
  6 set to 38400bps
  7 set to 57600bps
  8 set to 115200bps
 */

class BML{
  protected:
  Stream& _stream;
  private:
  byte convertBaudrate(unsigned long baud);
  static unsigned int _waitTime;
  String _deviceName = "UNKNOWN";
  String _pin = "UNKNOWN";
  byte _baudRate = 4;
  bool waitForRespond(String textRespond, unsigned int time = _waitTime);
  void clearBuffer();
  public:
  BML(Stream& str, unsigned long baudRate = 9600): _stream(str){
    _baudRate = convertBaudrate(baudRate);
  }
  void reset();
  bool unPlug();
  bool untilPlug(unsigned int time = _waitTime);//max wait taime 65s, you give value in milisec
  void waitTime(unsigned int time); //how long wait for respong, you give value in milisec
  bool setDeviceName(String deviceName, unsigned int time = _waitTime);
  String getDeviceName();
  bool setPin(String Pin, unsigned int time = _waitTime);
  String getPin();
  bool setBaudRate(unsigned long baudRate, unsigned int time = _waitTime);
  String deviceVersion(unsigned int time = _waitTime);
};

#endif
