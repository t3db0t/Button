/* $Id$
||
|| @file 		       Button.cpp
|| @author 		     Alexander Brevig              <alexanderbrevig@gmail.com>        
|| @url            http://alexanderbrevig.com
||
|| @description
|| | This is a Hardware Abstraction Library for Buttons
|| | It providea an easy way of handling buttons
|| #
||
|| @license LICENSE_REPLACE
||
*/

#ifndef Button_h
#define Button_h

#include <inttypes.h>

#define BUTTON_PULLUP HIGH
#define BUTTON_PULLUP_INTERNAL 2
#define BUTTON_PULLDOWN LOW

class Button;
typedef void (*buttonEventHandler)(Button&);

class Button {
  public:
  
    Button(uint8_t buttonPin, uint8_t buttonMode=BUTTON_PULLUP_INTERNAL, bool _debounceMode=true, int _debounceDuration=20);
    
    uint8_t             pin;
    void pullup(uint8_t buttonMode);
    void pulldown();
    void process();

    bool isPressed(bool proc=true);
    bool wasPressed(bool proc=true);
    bool stateChanged(bool proc=true);
    bool uniquePress();
    
    void setHoldThreshold(unsigned int holdTime);
    bool held(unsigned int time=0);
    bool heldFor(unsigned int time);
    
    void pressHandler(buttonEventHandler handler);
    void releaseHandler(buttonEventHandler handler);
    void clickHandler(buttonEventHandler handler);
    void holdHandler(buttonEventHandler handler, unsigned int holdTime=0);
  
    unsigned int holdTime() const;
    inline unsigned int presses() const { return numberOfPresses; }
    
    bool operator==(Button &rhs);
    
  private: 
    uint8_t             mode;
    uint8_t             state;
    bool                debounceMode;
    unsigned int        pressedStartTime;
    unsigned int        holdEventThreshold;
    unsigned long       debounceStartTime;
    int                 debounceDuration;
    buttonEventHandler  cb_onPress;
    buttonEventHandler  cb_onRelease;
    buttonEventHandler  cb_onClick;
    buttonEventHandler  cb_onHold;
    unsigned int        numberOfPresses;
    bool                triggeredHoldEvent;
};

#endif