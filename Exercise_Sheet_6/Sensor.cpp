//
// Created by McRebel on 09.05.2022.
//

#include <iostream>
#include "Sensor.h"
#include "RobotException.h"

int Distancesensor::checkSensor() {
    int randvalue = rand() % 100;
    if(randvalue < 15){
        throw InternalErrorExceptionn("throw InternalErrorException!");
    }
    else if(randvalue >= 15 && randvalue < 15+5){
        throw CriticalDangerException("throw CriticalDangerException!");
    } else{
        int dangerLevel = rand() % 7;
        std::cout << "my DistancesensorDangerlevel = " << dangerLevel << std::endl;
        return dangerLevel;
    }
}

int Cliffsensor::checkSensor() {
    int randvalue = rand() % 100;
    if(randvalue < 5){
        throw InternalErrorExceptionn("throw InternalErrorException!");
    }
    else if(randvalue >= 5 && randvalue < 10+5){
        throw CriticalDangerException("throw CriticalDangerException!");
    } else{
        int dangerLevel = rand() % 5;
        std::cout << "my CliffsensorDangerlevel = " << dangerLevel << std::endl;
        return dangerLevel;
    }
}

int Camerasensor::checkSensor() {
    int randvalue = rand() % 100;
    if(randvalue < 15){
        throw InternalErrorExceptionn("throw InternalErrorException!");
    }
    else if(randvalue >= 15 && randvalue < 20+15){
        throw CriticalDangerException("throw CriticalDangerException!");
    } else{
        int dangerLevel = rand() % 10;
        std::cout << "my CameraSensorDangerlevel = " << dangerLevel << std::endl;
        return dangerLevel;
    }
}
