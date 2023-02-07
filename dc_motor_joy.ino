// Arduino joystick DC motor speed and rotation direction control

#define joystickx     A0
#define joysticky     A1
#define pwm1          9
#define pwm2         10
#define pwm3         3
#define pwm4         11


int motor_control;

void setup() {
  TCCR1A = 0b00000001;  // 8bit
  TCCR1B = 0b00000010;  // x8 phase correct
  TCCR2B = 0b00000010;  // x8
  TCCR2A = 0b00000001;  // phase correct
  pinMode(pwm1,   OUTPUT);
  pinMode(pwm2,   OUTPUT);
  pinMode(pwm3,   OUTPUT);
  pinMode(pwm4,   OUTPUT);

}

void loop() {
  motor_control = analogRead(joystickx);
  motor_control >>= 1;
  if(motor_control > 255){
    digitalWrite(pwm2, 0);
    analogWrite(pwm1, (motor_control - 256));
  }
  else
    if(motor_control < 255){
      digitalWrite(pwm1, 0);
      analogWrite(pwm2, (255 - motor_control));
    }
    else{
      digitalWrite(pwm1, 0);
      digitalWrite(pwm2, 0);
    }
  motor_control = analogRead(joysticky);
  motor_control >>= 1;
  if(motor_control > 255){
    digitalWrite(pwm4, 0);
    analogWrite(pwm3, (motor_control - 256));
  }
  else
    if(motor_control < 255){
      digitalWrite(pwm3, 0);
      analogWrite(pwm4, (255 - motor_control));
    }
    else{
      digitalWrite(pwm3, 0);
      digitalWrite(pwm4, 0);
    }  
}
