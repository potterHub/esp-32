#define PIN_ANALOG_IN 4
#define PIN_LED 25
#define CHAN 0

void setup() {
  // starts the arduino serial comunications with another devices (in this case computer)
  // set the serial monitor baud and should match with the one from the ui
  // baud rate == bits transmited by secound (symbols/secound)
  // Serial.begin(115200);

  // 1000 hz -> frequency
  // resolution -> 12 bit
  ledcSetup(CHAN, 1000, 12);
  ledcAttachPin(PIN_LED, CHAN);
}

void loop() {
  // set pin that is going to read the analog signal (voltage given by the potenciometer in adc value)
  int adcVal = analogRead(PIN_ANALOG_IN);
  // 12 bits resolution -> 2^12 = 4096 -> range [0, 4095] -> analog read read in digital

  // adcVal re-map to pwmVal can be remap directly since channel acepts 12 bit resution and anolog signal
  int pwmVal = adcVal;
  ledcWrite(CHAN, pwmVal); // set the pulse width.

  // - Re-maps a number from one range to another.
  // - In this case maps the volage valeu from adcVal range [0,4095] to [0, 255]
  // - long map(long value,long fromLow,long fromHigh,long toLow,long toHigh);
  // int dacVal = map(adcVal, 0, 4095, 0, 255);
  
  // - write the digital to analog converstion
  // dacWrite(DAC1, dacVal);
  // - use the formula to convert adc values into 
  // double voltage = adcVal / 4095.0 * 3.3;
  // Serial.printf("ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV\n", adcVal, dacVal, voltage);
  // delay(200);
}

