/*
||
|| @file ChangeState.ino
|| @version 1.0
|| @author Ted Hayes
|| @contact ted.hayes@liminastudio.com
||
|| @description
|| | Detects a state change in the button
|| #
||
|| @license
|| | Copyright (c) 2012 Ted Hayes. All rights reserved.
|| #
||
*/

#include <Button.h>

//create a Button object at pin 12
/*
|| Wiring:
|| GND -----/ ------ pin 12
*/
Button button = Button(12, BUTTON_PULLUP_INTERNAL);

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT); //debug to led 13
}

void loop(){
  if(button.uniquePress()){
    Serial.println("Button Pressed");
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
}