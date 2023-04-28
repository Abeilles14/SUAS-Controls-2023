// // #define ESC 0
// // #define ESC_FREQ 50

#define CLUTCH 11

void setup() {
    // teensey serial config
  // Serial.begin(9600);

  // OUTPUT PIN CONFIG
  // pinMode(ESC, OUTPUT);
  pinMode(CLUTCH, OUTPUT);

  // analogWriteFrequency(ESC, ESC_FREQ);
  digitalWrite(CLUTCH, HIGH);
}

void loop() {
  if (Serial.available()) {
    // char dc = Serial.read();

    int clutch_state = Serial.parseInt();;
    if (Serial.read() == '\n') {}

    digitalWrite(CLUTCH, clutch_state);
    Serial.printf("Setting clutch to %d\n", clutch_state);
    Serial.flush();

    // analogWrite(ESC, (int) dc);
    // Serial.printf("Setting DC to %d\n", (int) dc);
  }

}