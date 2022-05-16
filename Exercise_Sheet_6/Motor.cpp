//
// Created by McRebel on 09.05.2022.
//

#include <iostream>
#include "Motor.h"
#include "RobotException.h"




void Motor::setSpeed(int speed) {
    if(speed >=0 && speed < 11){
        motorSpeed = speed;
        std::cout << "calling setSpeed() speed = " << speed << std::endl;
    } else{
        throw InvalidMotorspeedException("Invalid motorSpeed, Speed must between 0 and 10!");
    }
}

int Motor::getSpeed() {
    std::cout << "calling getSpeed(), speed = " << motorSpeed << std::endl;
    return motorSpeed;
}

void Motor::emergencyBrake() {
    setSpeed(0);
    std::cout << "Emergencybreak! setSpeed() = 0" << std::endl;
}
