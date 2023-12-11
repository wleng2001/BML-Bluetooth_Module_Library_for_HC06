#include "BML.h"

static unsigned int BML::_waitTime = 1000;

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

byte BML::convertBaudrate(unsigned long baud){
  switch(baud){
    case 1200:
    return 1;
    
    case 2400:
    return 2;
    
    case 4800:
    return 3;
    
    case 9600:
    return 4;

    case 19200:
    return 5;

    case 38400:
    return 6;

    case 57600:
    return 7;

    case 115200:
    return 8;
    
    default:
    return 4;
  }
}

void BML::clearBuffer(){
  while(_stream.available()>0){
    _stream.read();
  }
}

bool BML::waitForRespond(String textRespond, unsigned int time = _waitTime){
  char* text = new char[textRespond.length()];
  unsigned long start_time = millis();
  bool isRespond = _stream.find(text);
  while((start_time+time)>millis()){
    isRespond = _stream.find(text);
    if(isRespond == 1){
      break;
    }
  }
  return isRespond;
}

void BML::reset(){
  _stream.print("AT+RESET");
  waitForRespond("OK");
}

bool BML::unPlug(){
  _stream.print("AT");
  return _stream.find("OK");
}

bool BML::untilPlug(unsigned int time = _waitTime){
  clearBuffer();
  unPlug();
  return waitForRespond("OK", time);
}

void BML::waitTime(unsigned int time){
  _waitTime = time;
}

bool BML::setDeviceName(String deviceName, unsigned int time = _waitTime){
  clearBuffer();
  _stream.print("AT+NAME"+deviceName);
  bool isChangeName = waitForRespond("OK", time);
  if(time == 0 || isChangeName){
    _deviceName = deviceName;
  }
  return isChangeName;
}

String BML::getDeviceName(){
  return _deviceName;
}

bool BML::setPin(String Pin, unsigned int time = _waitTime){
  clearBuffer();
  _stream.print("AT+PIN"+Pin);
  bool isChangePin = waitForRespond("OK", time);
  if(isChangePin == 1 || time == 0){
    _pin = Pin;
  }
  return isChangePin;
}

String BML::getPin(){
  return _pin;
}

bool BML::setBaudRate(unsigned long baudRate, unsigned int time = _waitTime){
  clearBuffer();
  _stream.print("AT+BAUD"+String(convertBaudrate(baudRate)));
  bool isSetBaud = waitForRespond("OK", time);
  return isSetBaud;
}

String BML::deviceVersion(unsigned int time = _waitTime){
  String version = "";
  clearBuffer();
  _stream.print("AT+VERSION");
  unsigned long wait_time = millis();
  while(time+wait_time>millis()){
    
  }
  while(_stream.available()>0){
    version+=_stream.readString();
  }
  return version;
}
