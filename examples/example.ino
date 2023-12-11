/*If device configure bluetooth module built in led start glowing.
 * If you write "config" in terminal, when you are connected to bluetooth module it write some information about it."
 */

#include "BML.h"
/*uncomment it if you want use software serial and comment line 12
#include <SoftwareSerial.h>

SoftwareSerial s(3,4);
BML bml(s);
*/
BML bml(Serial);

String version = "";
bool baud = 0;
bool setPin = 0;
bool plug = 0;
bool name = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  Serial.println("Turn on");
  //s.begin(9600); //uncomment if you want use software serial
  delay(3000);
  bml.waitTime(4000);
  bml.reset();
  plug = bml.untilPlug();
  name = bml.setDeviceName("MyHC06");
  setPin = bml.setPin("9999");
  baud = bml.setBaudRate(9600);
  version = bml.deviceVersion();
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop(){
  String text = "";
  if(Serial.available()>0){
    text = Serial.readStringUntil('\n');
    text = text.substring(0,text.length()-1);
  }
  if(text == "config"){
    Serial.println("if succeed connect to bt module: "+String(plug));
    Serial.println("succeed set name: "+String(name));
    Serial.println("succeed set PIN: "+String(setPin));
    Serial.println("succeed set baudrate: "+String(baud));
    Serial.println("HC-06 vesrion: "+String(version));
  }
}
