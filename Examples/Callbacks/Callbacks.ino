/*
||
|| @file ChangeState.ino
|| @version 1.0
|| @author Ted Hayes
|| @contact ted.hayes@liminastudio.com
||
|| @description
|| | Demonstrates the use of asynchronous callback functions instead of synchronous state checks
|| #
||
|| @license
|| | Copyright (c) 2012 Ted Hayes. All rights reserved.
|| #
||
*/

#include <Button.h>

//create two Button objects for two physical switches
/*
|| Wiring:
|| GND -----/ ------ pin 12
|| GND -----/ ------ pin 11
*/

// Uses debounce mode. You may need to experiment with the debounce duration
// for your particular switch.

Button button = Button(12, BUTTON_PULLUP_INTERNAL, true, 50);
Button button2 = Button(11, BUTTON_PULLUP_INTERNAL, true, 50);

// Callbacks
// "Button& b" is a reference to the button that triggered the callback
// This way we can access its information so we know which button it was
void onPress(Button& b){
	Serial.print("onPress: ");
	Serial.println(b.pin);
	digitalWrite(13,HIGH);
}

void onRelease(Button& b){
	Serial.print("onRelease: ");
	Serial.println(b.pin);
	digitalWrite(13,LOW);
}

void onHold(Button& b){
	Serial.print("Held for at least 1 second: ");
	Serial.println(b.pin);
}

void setup(){
  Serial.begin(9600);
  Serial.println("Started");
  pinMode(13,OUTPUT); //debug to led 13

  // Assign callback functions
  button.pressHandler(onPress);
  button.releaseHandler(onRelease);
  button.holdHandler(onHold, 1000); // must be held for at least 1000 ms to trigger

  button2.pressHandler(onPress);
  button2.releaseHandler(onRelease);
  button2.holdHandler(onHold, 1000); // must be held for at least 1000 ms to trigger
}

void loop(){
  // update the buttons' internals
  button.process();
  button2.process();
}