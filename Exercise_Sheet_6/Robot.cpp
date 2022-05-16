//
// Created by McRebel on 09.05.2022.
//

#include "Robot.h"
#include <algorithm>
#include "RobotException.h"
#include <unistd.h>

int Robot::addSensor(Sensor *sensor) {
    int myId = nextId++;
    sensors.insert(std::pair<const int, Sensor*>(myId, sensor));
    std::cout << "MyNewSensor has ID: " << myId << std::endl;
    return myId;
}

Sensor *Robot::getSensor(int id) {
    return sensors.at(id);
}

void Robot::deleteSensor(int id) {
    sensors.erase(id);

}

void Robot::eventLoop(int iterations) {
    int statuscount = 0;
    int loopcount = 1;
    while (iterations >= 0){
        std::cout << "********-----Iteration count: " << loopcount++ << " -----********"<< std::endl;
        int maxDangerLevel = 0;

        if(status != 2){
            for(auto &s: sensors){
                try{
                    int currentDangeLevel = s.second->checkSensor();
                    if(currentDangeLevel > maxDangerLevel){
                        maxDangerLevel = currentDangeLevel;
                    }
                    std::cout << "Aktuelles Gefahrenlevel: " << currentDangeLevel << std::endl;
                }catch (CriticalDangerException &e){
                    motor.emergencyBrake();
                    status = 2;
                    statuscount = 5;
                    std::cout << "Kritische Gefhar! Notbremsung wurde eingeleitet! Roboter bleibt fuer 5 Iterationen stehen!" << std::endl;
                    break;
                }catch (InternalErrorExceptionn &e){
                    motor.setSpeed(1);
                    status = 1;
                    statuscount = 5;
                    std::cout << "Interner Fehler! Minimale geschwindigkeit fuer 5 Iterationen!";
                }
            }

        }

        if(status == 0){
        std::cout << "Aktuell groesstes Gefahrenlevel: " << maxDangerLevel << std::endl;
        motor.setSpeed(10 - maxDangerLevel);
        } else{
            std::cout << "Statuscount: " << statuscount << std::endl;
            statuscount--;
            if(statuscount <=0){
                std::cout << "Roboter kehrt in den Normalbetrieb zurueck! " << std::endl;
                status = 0;
            }
        }
        if(iterations > 0){
            iterations--;
            if(iterations <= 0){
                break;
            }
        }
        sleep(1);
    }

}
