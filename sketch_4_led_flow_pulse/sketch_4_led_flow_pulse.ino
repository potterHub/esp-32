const byte ledPins[] = { 15, 2, 0, 4, 5, 18, 19, 21, 22, 23 };  //define led pins
// define 10 PWM channels
const byte chns[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
// define 30 pulse values.
const int dutys[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      1023, 512, 256, 128, 64, 32, 16, 8, 4, 2,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  //define the pwm dutys
                      
int ledCounts;         //led counts
int delayTimes = 50;   //flowing speed ,the smaller, the faster

void setup() {
  // get the led counts
  ledCounts = sizeof(ledPins);

  //setup the pwm channels
  for (int i = 0; i < ledCounts; i++) {
    // set the frequency of 10 PWM channels to 1000Hz, the accuracy to 10bits
    ledcSetup(chns[i], 1000, 10);
    // Attach GPIO to these PWM channels
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  // flowing one side to other side
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < ledCounts; j++) {
      ledcWrite(chns[j], dutys[i + j]);
    }
    delay(delayTimes);
  }

  // flowing one side to other side
  for (int i = 0; i < 20; i++) {
    for (int j = ledCounts - 1; j > -1; j--) {
      ledcWrite(chns[j], dutys[i + (ledCounts - 1 - j)]);
    }
    delay(delayTimes);
  }
}
