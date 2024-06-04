#define PIN_SENSOR_IN 4
#define PIN_LED 12

// pwd (Pulse Width Modulation) channel
#define CHAN 0

// max and min digital values for the light
#define LIGHT_MIN 372
#define LIGHT_MAX 2048

void setup() {
  ledcSetup(CHAN, 1000, 12);
  ledcAttachPin(PIN_LED, CHAN);
  LOW
}

void loop() {
  // read adc (digital represetation of the analog signal)
  int adcVal = analogRead(PIN_SENSOR_IN);
  // contraint it to the led min and max values
  int adcContraintVal = constrain(adcVal, LIGHT_MIN, LIGHT_MAX);
  // map adc value into pwm ((Pulse Width Modulation)) value
  int pwmVal = map(adcContraintVal, LIGHT_MIN, LIGHT_MAX, 0, 4095);
  
  ledcWrite(CHAN, pwmVal); // set the pulse width (pw).

  delay(10);
}
