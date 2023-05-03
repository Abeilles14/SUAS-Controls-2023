/*
300Hz
75 - fully extended - 2.5cm
160 - fully retracted - 0cm
75 - seat belt closed
115 - seat belt open
*/
// analog write = [0, 255] scale -> [0, 100]%

#define PWM1 0 
#define PWM2 1
#define MOTOR_FREQ 300

void setup() {
  Serial.begin(9600);

   // set servo
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  // analogWriteFrequency(PWM1, MOTOR_FREQ);
  // analogWriteFrequency(PWM2, MOTOR_FREQ);

  // analogWriteResolution(8);
}

void loop() {
  int pos1 = 0;
  int pos2 = 0;

  while (Serial.available() > 0) {

    pos1 = Serial.parseInt();
    if (Serial.read() == '\n') {}
    Serial.print("\r\nPWM1: %d", pos1);

    while(!Serial.available()) {}
    
    pos2 = Serial.parseInt();
    if (Serial.read() == '\n') {}
    Serial.print("\r\nPWM2: %d", pos2);

    analogWrite(PWM1, pos1);
    analogWrite(PWM2, pos2);
  }
}