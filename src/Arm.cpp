#include "Arm.h"
#include "Pins.h"
#include <Adafruit_PWMServoDriver.h>
#include <ServoDriver.h>

Arm Arm1(1, 0, 2); // ROT 0, EXT, 1
Arm Arm2(2, 0, 2); // ROT 0, EXT, 1
Arm Arm3(3, 0, 2); // ROT 0, EXT, 1
Arm Arm4(4, 0, 2); // ROT 0, EXT, 1
Arm Arm5(5, 0, 2); // ROT 0, EXT, 1
Arm Arm6(6, 0, 2); // ROT 0, EXT, 1

Arm::Arm(int arm_number, int RotationServoNumber, int ExtensionServoNumber) {

    // Limit Switch Pin Assignment
    switch (arm_number) {
        case 1:
            this->LS1 = LS11;
            this->LS2 = LS12;
            this->LS3 = LS13;
            this->LS4 = LS14;

        case 2:
            this->LS1 = LS21;
            this->LS2 = LS22;
            this->LS3 = LS23;
            this->LS4 = LS24;

        case 3:
            this->LS1 = LS31;
            this->LS2 = LS32;
            this->LS3 = LS33;
            this->LS4 = LS34;

        case 4:
            this->LS1 = LS41;
            this->LS2 = LS42;
            this->LS3 = LS43;
            this->LS4 = LS44;

        case 5:
            this->LS1 = LS51;
            this->LS2 = LS52;
            this->LS3 = LS53;
            this->LS4 = LS54;

        case 6:
            this->LS1 = LS61;
            this->LS2 = LS62;
            this->LS3 = LS63;
            this->LS4 = LS64;

        break;
    }

    // Set Servo Numbers
    this->Rotation.number = RotationServoNumber;
    this->Extension.number = ExtensionServoNumber;
}

void Arm::setRotation(int direction, int speed) {
    this->Rotation.speed = direction * speed;
    updateServoSpeed(this->Rotation.number, this->Rotation.speed);
}

void Arm::setExtension(int direction, int speed) {
    this->Extension.speed = direction * speed;
    updateServoSpeed(this->Extension.number, this->Extension.speed);
}

// LS1 - Extended
// LS2 - Cup
// LS3 - Retraction
// LS4 - ROTHome
