#define PIN_LED 2
#define PIN_BUTTON 13

// the setup function runs once when you press reset or power the board
void setup() {
  // init the pin led as output when using the input
  pinMode(PIN_LED, OUTPUT);

  // init the pint button as input
  pinMode(PIN_BUTTON, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    // reverse the pin led state
    // (if light on becames off, if light off becomes on)
    reverseGPIO(PIN_LED);

    waitToRemoveBounce(PIN_BUTTON);
  }
}

void reverseGPIO(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}

/**
Debounce for Push Button
The moment when a push button switch is pressed, it will not change from one state to another state
immediately. 

Due to tiny mechanical vibrations, there will be a short period of continuous buffeting before it
completely reaches another state too fast for humans to detect but not for computer microcontrollers. 

The same is true when the push button switch is released. This unwanted phenomenon is known as “bounce”.
Therefore, if we can directly detect the state of the push button switch, there are multiple pressing and
releasing actions in one pressing cycle. This buffeting will mislead the high-speed operation of the
microcontroller to cause many false decisions. 

Therefore, we need to eliminate the impact of buffeting. Our solution: 
  to judge the state of the button multiple times. Only when the button state is stable (consistent) over
a period of time, can it indicate that the button is actually in the ON state (being pressed).
This project needs the same components and circuits as we used in the previous section.
*/
void waitToRemoveBounce(int pin) {
  delay(20);

  while (digitalRead(pin) == LOW);

  delay(20);

  while (digitalRead(pin) == LOW);  
}
