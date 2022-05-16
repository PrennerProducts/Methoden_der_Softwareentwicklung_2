#include "Motor.h"
#include "RobotException.h"
#include <iostream>
#include "Sensor.h"
#include <random>
#include <ctime>
#include "Robot.h"


int main(){
    std::srand(time(0));

    Robot robot;
    robot.addSensor(new Camerasensor());
    robot.addSensor(new Distancesensor());
    robot.addSensor(new Cliffsensor());

    robot.eventLoop(5);




    return 0;
}