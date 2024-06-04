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
  // when pressing the button
  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(PIN_LED, HIGH);
    delay(2000);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}
