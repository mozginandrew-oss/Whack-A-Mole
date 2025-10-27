const int buttonPins[4] = {2, 0, 3, 1};
const int ledPins[4]    = {5, 6, 4, 7};


const int rounds = 10;
const unsigned long maxWait = 2000;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
    digitalWrite(ledPins[i], LOW);
  }
  randomSeed(analogRead(0));
  Serial.begin(115200);
}

void loop() {
  for (int round = 0; round < rounds; round++) {
    int idx = random(0, 4);
    digitalWrite(ledPins[idx], HIGH);

    unsigned long startTime = millis();
    bool hit = false;
    while (millis() - startTime < maxWait) {
      if (digitalRead(buttonPins[idx]) == LOW) {
        hit = true;
        break;
      }
    }

    digitalWrite(ledPins[idx], LOW);

    delay(300);
  }

  Serial.println("Game over!");

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(250);
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(250);
  }

  delay(5000);
}
