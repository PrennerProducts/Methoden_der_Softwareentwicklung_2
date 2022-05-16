//
// Created by McRebel on 09.05.2022.
//

#ifndef MSE2_ROBOTER_ROBOT_H
#define MSE2_ROBOTER_ROBOT_H

#include "Motor.h"
#include "RobotException.h"
#include <iostream>
#include "Sensor.h"
#include <random>
#include <ctime>
#include <map>


class Robot {
private:
    Motor motor;
    std::map<int, Sensor*> sensors;
    int nextId = 0;
    int status = 0; //0 = Normal, 1 = InternalError, 2 = Notstop



public:
    virtual ~Robot(){
        for(int i = 0; i < (int)sensors.size(); i++){
            std::cout << "Destructor deletet Sensor" << std::endl;
            delete sensors[i];
        }
    }

    int addSensor(Sensor* sensor);

    Sensor* getSensor(int id);

    void deleteSensor(int id);

    void eventLoop(int iterations);

};


#endif //MSE2_ROBOTER_ROBOT_H
