/*
300Hz
75 - fully extended - 2.5cm
160 - fully retracted - 0cm
*/

#define CLUTCH1 11
#define CLUTCH2 10
#define CLUTCH3 14
#define CLUTCH4 15
#define CLUTCH5 16

#define ACTUATOR1 0
#define ACTUATOR2 1
#define ACTUATOR3 2
#define ACTUATOR4 3
#define ACTUATOR5 4

#define ACT_OFF 90   // OUT (not active

#define ACT_ON 140    // IN (active 1)
#define ACT_FREQ 300

void setup() {
  // teensey serial config
  Serial.begin(9600);

  // OUTPUT PIN CONFIG
  // CLUTCHES
  pinMode(CLUTCH1, OUTPUT);
  pinMode(CLUTCH2, OUTPUT);
  pinMode(CLUTCH3, OUTPUT);
  pinMode(CLUTCH4, OUTPUT);
  pinMode(CLUTCH5, OUTPUT);

  // ACTUATORS
  pinMode(ACTUATOR1, OUTPUT);
  pinMode(ACTUATOR2, OUTPUT);
  pinMode(ACTUATOR3, OUTPUT);
  pinMode(ACTUATOR4, OUTPUT);
  pinMode(ACTUATOR5, OUTPUT);

  // INIT MOTORS
  digitalWrite(CLUTCH1, LOW);
  digitalWrite(CLUTCH2, LOW);
  digitalWrite(CLUTCH3, LOW);
  digitalWrite(CLUTCH4, LOW);
  digitalWrite(CLUTCH5, LOW);

  analogWriteFrequency(ACTUATOR1, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR2, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR3, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR4, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR5, ACT_FREQ); 
  analogWriteResolution(8);

  // INIT ACTUATORS POS
  }

void loop() {
  int type_sel = 0;
  int motor_sel = 0;
  int motor_state = 0;

  if (Serial.available()) {
    // choose actuator or clutch control
    Serial.printf("\nSelect Clutches or Actuators [1, 2]: ");
    type_sel = Serial.parseInt();
    // wait for serial
    while (!Serial.available()) {}

    if (type_sel == 1) {
      Serial.printf("\nSelect Clutch [1, 2, 3, 4, 5]: ");
      // choose clutch
      motor_sel = Serial.parseInt();
      if (Serial.read() == '\n') {}

      // wait for serial
      while (!Serial.available()) {}

      // set clutch ON/OFF
      Serial.printf("\nEnter Clutch State [0, 1] V: ");

      if (motor_sel == 1) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        digitalWrite(CLUTCH1, motor_state);

      } else if (motor_sel == 2) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        digitalWrite(CLUTCH2, motor_state);

      } else if (motor_sel == 3) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        digitalWrite(CLUTCH3, motor_state);

      } else if (motor_sel == 4) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        digitalWrite(CLUTCH4, motor_state);

      } else if (motor_sel == 5) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        digitalWrite(CLUTCH5, motor_state);

      } else {
        Serial.printf("\nInvalid command");
      }
    } else if (type_sel == 2) {
      Serial.printf("\nSelect Actuator [1, 2, 3, 4, 5]: ");
      // choose clutch
      motor_sel = Serial.parseInt();
      if (Serial.read() == '\n') {}

      // wait for serial
      while (!Serial.available()) {}
      // set clutch ON/OFF
      Serial.printf("\nEnter Actuator state (ON/OFF) [1, 0]: ");
      motor_state = Serial.parseInt();

      if (Serial.read() == '\n') {}

      if (motor_state == 1) {
        motor_state = ACT_ON;
      } else if (motor_state == 0) {
        motor_state = ACT_OFF;
      }

      switch(motor_sel) {
          case 1:
          analogWrite(ACTUATOR1, motor_state);
          break;

          case 2:
          analogWrite(ACTUATOR2, motor_state);
          break;

          case 3:
          analogWrite(ACTUATOR3, motor_state);
          break;

          case 4:
          analogWrite(ACTUATOR4, motor_state);
          break;

          case 5:
          analogWrite(ACTUATOR5, motor_state);
          break;
      }
    }
    
    Serial.printf("\nSetting type %d motor %d to %d\n", type_sel, motor_sel, motor_state);
  }
    Serial.flush();
}