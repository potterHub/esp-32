#define PIN_BUZZER 13
#define PIN_BUTTON 4
#define CHN 0 //define the pwm channel

// The resolution determines the number of available duty cycles for a given period. For example, 
// a 10-bit resolution will result in 1,024 discrete duty cycles while an 8-bit resolution will result in 256 discrete duty cycles.
#define RESOLUTION 10

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  // ledcSetup(ledChannel, freq, resolution);
  ledcSetup(CHN, 0, RESOLUTION);   //setup pwm channel
  ledcAttachPin(PIN_BUZZER, CHN); //attach the led pin to pwm channel
  // ledcWrite(ledChannel, dutyCycle); 
  ledcWriteTone(CHN, 2000);       //Sound at 2KHz for 0.3 seconds
  delay(300);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    alert();
  } else {
    // ledcWrite(ledChannel, dutyCycle); 
    ledcWriteTone(CHN, 0); //Sound at 0 KHz
  }
}

void alert() {
 float sinVal; // Define a variable to save sine value
 int toneVal; // Define a variable to save sound frequency

  // this code uses the sin function to generate variable intensity sound wave
  for (int x = 0; x < 360; x += 10) { // X from 0 degree->360 degree
    sinVal = sin(x * (PI / 180)); // Calculate the sine of x
    toneVal = 2000 + sinVal * 500; //Calculate sound frequency according to the sine of x
  
    // ledcWrite(ledChannel, dutyCycle); 
    ledcWriteTone(CHN, toneVal); //Sound at toneVal KHz for 10 seconds
    delay(10);
  }
}
