#define CHN 0      //define the pwm channel (0-15)
#define FRQ 1000   //define the pwm frequenc
#define PWM_BIT 8  //define the pwm precision

#define PIN_LED 2  //define the led pin

void setup() {
  // Set the frequency and accuracy of a pwm channel (1000hz and 8 bit in channel 0)
  ledcSetup(CHN, FRQ, PWM_BIT);

  //attach the led pin to pwm channel
  ledcAttachPin(PIN_LED, CHN);
}

void loop() {
  // 255 because pwm of 8 bits
  // make light fade in
  for (int i = 0; i < 255; i++) {
    // Writes the pulse width value to a PWM channel.
    ledcWrite(CHN, i);
    delay(10);
  }
  // make light fade out
  for (int i = 255; i > -1; i--) {
    // Writes the pulse width value to a PWM channel.
    ledcWrite(CHN, i);
    delay(10);
  }
}