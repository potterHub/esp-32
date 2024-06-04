#define PIN_BUZZER 13
#define PIN_BUTTON 4

void setup() {
  // pin 13 is output (sends signal +)
  pinMode(PIN_BUZZER, OUTPUT);

  // pin 4 is input (receives signal -)
  pinMode(PIN_BUTTON, INPUT);
}

// low means low is no signal and high means has signal
void loop() {
  // if signal low we are not clicking the button
  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(PIN_BUZZER, HIGH);
  } else {
    digitalWrite(PIN_BUZZER, LOW);
  }
}
