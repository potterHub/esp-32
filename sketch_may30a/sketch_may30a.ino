#define GREEN_LED_PIN 14
#define YELLOW_LED_PIN 13
#define RED_LED_PIN 12
#define BUTTON_PIN 4

#define YELLOW_DELAY 350 * 14
#define YELLOW_BLINK_DELAY 350
#define GREEN_DELAY 30000
#define RED_DELAY 20000

struct State {
  int pin;
  unsigned long delayMillis;
  bool isBlinking;
};
bool blinkingState = HIGH;

struct State state;
unsigned long lastStateChangeMillis = 0;
unsigned long lastBlinkChangeMillis = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  // set leds as output mode
  pinMode (GREEN_LED_PIN, OUTPUT);
  pinMode (YELLOW_LED_PIN, OUTPUT);
  pinMode (RED_LED_PIN, OUTPUT);
  pinMode (BUTTON_PIN, INPUT);

  lastStateChangeMillis = millis();
  state = {GREEN_LED_PIN, GREEN_DELAY, false};
  digitalWrite (state.pin, HIGH);
}
void loop() {
  unsigned long currentMillis = millis();

  bool buttonState = digitalRead(BUTTON_PIN);
  
  if(buttonState == HIGH && state.pin == GREEN_LED_PIN){
    changeLightState(currentMillis);
  }

  if(currentMillis - lastStateChangeMillis >= state.delayMillis){
    changeLightState(currentMillis);
  }

  if (state.isBlinking && currentMillis - lastBlinkChangeMillis >= YELLOW_BLINK_DELAY) {
    lastBlinkChangeMillis = currentMillis;   

    blinkingState = !blinkingState;
    digitalWrite(state.pin, blinkingState);
  }
}

void changeLightState(int currentMillis){
  digitalWrite (state.pin, LOW);

  switch(state.pin){
    case RED_LED_PIN:
      state = {GREEN_LED_PIN, GREEN_DELAY, false};
      break;
    case YELLOW_LED_PIN:
      state = {RED_LED_PIN, RED_DELAY, false};
      break;
    case GREEN_LED_PIN:
      state = {YELLOW_LED_PIN, YELLOW_DELAY, true};
      break;
  }

  blinkingState = HIGH;
  lastStateChangeMillis = currentMillis;
  digitalWrite (state.pin, blinkingState);


  if(state.isBlinking){
    lastBlinkChangeMillis = millis();
  }
}
