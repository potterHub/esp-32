// 15 - R, 2 - G, 4 - B
const byte ledPins[] = { 15, 2, 4 };  //define red, green, blue led pins (were the negatives are connected)
const byte chns[] = { 0, 1, 2 };      //define the pwm channels
int red, green, blue;

void setup() {
  for (int i = 0; i < 3; i++) {  //setup the pwm channels,1KHz,8bit
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  setColor(red, green, blue);
  delay(200);
}

void setColor(byte r, byte g, byte b) {
  ledcWrite(chns[0], 255 - r);  //Common anode LED, low level to turn on the led.
  ledcWrite(chns[1], 255 - g);
  ledcWrite(chns[2], 255 - b);
}
