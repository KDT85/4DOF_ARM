#include <Servo.h>

Servo base;
Servo lower;
Servo upper;
Servo gripper;

int minAngle = 35;
int midAngle = 90;
int maxAngle = 100;
int speed = 5;

Servo servoArray[2] = {lower, upper};

void moveServo(Servo &servo, int position){
  servo.write(position);
}

/*fake inverse kinematics*/
void upAndDown(){
  int one = 1;
  for (int i = minAngle; i <= maxAngle; i++) {
    //moveServo(upper, i);
    upper.write(i);
    lower.write(maxAngle - one);
    delay(speed);
    Serial.print("1upper = ");
    Serial.println(i);
    Serial.print("1lower = ");
    Serial.println(maxAngle - one);
    one++;
  }
  
  one = 1;
  for (int i = maxAngle; i >= minAngle; i--) {
    //moveServo(upper, i);
    
    upper.write(i);
    lower.write(minAngle + one);
    delay(speed);
    Serial.print("2upper = ");
    Serial.println(i);
    Serial.print("2lower = ");
    Serial.println(minAngle + one);
    one++;
  }
}

void setup() {
  // put your setup code here, to run once:
  base.attach(5);
  lower.attach(4);
  upper.attach(0);
  gripper.attach(2);

  //base.write(90);
  //lower.write(90);
  
  Serial.begin(9600); // Set the baud rate to 9600 (or your desired rate)
}

void loop() {
  // put your main code here, to run repeatedly:

  upAndDown();
  
}
