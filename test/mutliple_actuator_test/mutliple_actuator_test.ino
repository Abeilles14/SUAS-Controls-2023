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

#define ACT_OFF 160
#define ACT_ON 75
#define ACT_FREQ 300

void setup() {
  // teensey serial config
  Serial.begin(9600);

  // OUTPUT PIN CONFIG
  // ACTUATORS
  pinMode(ACTUATOR1, OUTPUT);
  pinMode(ACTUATOR2, OUTPUT);
  pinMode(ACTUATOR3, OUTPUT);
  pinMode(ACTUATOR4, OUTPUT);
  pinMode(ACTUATOR5, OUTPUT);

  analogWriteFrequency(ACTUATOR1, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR2, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR3, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR4, ACT_FREQ); 
  analogWriteFrequency(ACTUATOR5, ACT_FREQ); 
  analogWriteResolution(8);

  analogWrite(ACTUATOR1, 100);
  }

void loop() {
  //int type_sel = 0;
  int motor_sel = 0;
  int motor_state = 0;

  if (Serial.available()) {
      // choose actuator
      Serial.printf("\r\nSelect Actuator [1, 2, 3, 4, 5]: ");
      motor_sel = Serial.parseInt();
      if (Serial.read() == '\n') {}

      // wait for serial
      while (!Serial.available()) {}

      // set clutch ON/OFF
      Serial.printf("\r\nEnter Actuator State (DC) [75, 160] %: ");

      if (motor_sel == 1) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        analogWrite(ACTUATOR1, motor_state);

      } else if (motor_sel == 2) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        analogWrite(ACTUATOR2, motor_state);

      } else if (motor_sel == 3) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        analogWrite(ACTUATOR3, motor_state);

      } else if (motor_sel == 4) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        analogWrite(ACTUATOR4, motor_state);

      } else if (motor_sel == 5) {
        motor_state = Serial.parseInt();
        if (Serial.read() == '\n') {}

        analogWrite(ACTUATOR5, motor_state);

      } else {
        Serial.printf("Invalid command\n");
      }

    Serial.printf("Setting number %d to %d\n", motor_sel, motor_state);
  }
    Serial.flush();
}