/**
 * arcade keyboard
 * @author: Dennis Lehmann
 * @platform: Arduino/Genuino Micro or compatible
 * 
 * further documentation:
 * ----------------------
 * @see http://www.asciitable.com/ ACSII-Table
 * @see https://www.arduino.cc/en/Reference/MouseKeyboard Arduino Mouse and Keyboard lib doc
 * @see https://www.arduino.cc/en/Reference/KeyboardModifiers Keyboard Modifiers
 * 
*/
#include <Keyboard.h>

int buttonCount = 10;
int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 16};
int buttonKeys[] = {
  KEY_RIGHT_ARROW, 
  KEY_LEFT_ARROW, 
  KEY_DOWN_ARROW, 
  KEY_UP_ARROW,
  KEY_RETURN,
  KEY_ESC, 
  KEY_LEFT_CTRL,
  32, // space
  KEY_F1,
  KEY_F2 
}; 
int buttonStates[] = {0,0,0,0,0,0,0,0,0}; // array to store button states

void setup()
{
  // set every button as input
  for (int i=0; i<buttonCount; i++) {
    pinMode(buttonPins[i], INPUT); 
  }
  Keyboard.begin(); //  start keyboard emulating
}

void loop()
{
  
  // press button
  for (int i=0; i<buttonCount; i++) {
    if (digitalRead(buttonPins[i]) == 1 && buttonStates[i] == 0) {
      Keyboard.press(buttonKeys[i]);
      buttonStates[i] = 1;
    }
  }

  delay(10); // avoid button bounce effects
  
  // release button
  for (int i=0; i<buttonCount; i++) {
    if (digitalRead(buttonPins[i]) == 0 && buttonStates[i] == 1) {
      Keyboard.release(buttonKeys[i]);
      buttonStates[i] = 0;
    }
  }
  
}

