// #define ESC 0
// #define ESC_FREQ 50

#define CLUTCH1 11
#define CLUTCH2 10
#define CLUTCH3 14
#define CLUTCH4 15
#define CLUTCH5 16

void setup() {
  // teensey serial config
  // Serial.begin(9600);

  // OUTPUT PIN CONFIG
  pinMode(CLUTCH1, OUTPUT);
  pinMode(CLUTCH2, OUTPUT);
  pinMode(CLUTCH3, OUTPUT);
  pinMode(CLUTCH4, OUTPUT);
  pinMode(CLUTCH5, OUTPUT);

  digitalWrite(CLUTCH1, LOW);
  digitalWrite(CLUTCH2, LOW);
  digitalWrite(CLUTCH3, LOW);
  digitalWrite(CLUTCH4, LOW);
  digitalWrite(CLUTCH5, LOW);
  }

void loop() {
  int clutch_state = 0;
  int clutch_sel = 0;

  if (Serial.available()) {
    Serial.printf("Select Clutch [1, 2, 3, 4, 5]: ");
    clutch_sel = Serial.parseInt();
    if (Serial.read() == '\n') {}

    Serial.printf("Enter Clutch State [0, 1] V: ");
    while (!Serial.available()) {}

    if (clutch_sel == 1) {
      clutch_state = Serial.parseInt();
      if (Serial.read() == '\n') {}

      digitalWrite(CLUTCH1, clutch_state);

    } else if (clutch_sel == 2) {
      clutch_state = Serial.parseInt();
      if (Serial.read() == '\n') {}

      digitalWrite(CLUTCH2, clutch_state);

    } else if (clutch_sel == 3) {
      clutch_state = Serial.parseInt();
      if (Serial.read() == '\n') {}

      digitalWrite(CLUTCH3, clutch_state);

    } else if (clutch_sel == 4) {
      clutch_state = Serial.parseInt();
      if (Serial.read() == '\n') {}

      digitalWrite(CLUTCH4, clutch_state);

    } else if (clutch_sel == 5) {
      clutch_state = Serial.parseInt();
      if (Serial.read() == '\n') {}

      digitalWrite(CLUTCH5, clutch_state);

    } else {
      Serial.printf("Invalid command\n");
    }

    Serial.printf("Setting clutch %d to %d\n", clutch_sel, clutch_state);
  }
    Serial.flush();
}