here#include <AFMotor.h>
#include <SoftwareSerial.h>

// Create objects for the motors
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4); 

// Create a SoftwareSerial object for Bluetooth communication
// Pins (RX, TX)
SoftwareSerial bluetooth(0,1 ); // Arduino RX pin, Arduino TX pin

const int motorSpeed = 200; // Speed of the motors

void setup() {
  // Set motor speeds
  motor1.setSpeed(motorSpeed);
  motor2.setSpeed(motorSpeed);
  motor3.setSpeed(motorSpeed);
  motor4.setSpeed(motorSpeed);

  // Start serial communication with the computer for debugging
  Serial.begin(9600);
  // Start serial communication with the Bluetooth module
  bluetooth.begin(9600);

  Serial.println("Robot Ready. Connect via Bluetooth.");
}

void loop() {
  // Check if data is available from the Bluetooth module
  if (bluetooth.available()) {
    char command = bluetooth.read(); // Read the incoming character

    // Print the command to the serial monitor for debugging
    Serial.print("Command received: ");
    Serial.println(command);

    // Control the motors based on the received command
    if (command == 'f') { // Forward
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    } else if (command == 'b') { // Backward
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    } else if (command == 'l') { // Turn Left
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
    } else if (command == 'r') { // Turn Right
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
    } else if (command == 's') { // Stop
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
  }
}
