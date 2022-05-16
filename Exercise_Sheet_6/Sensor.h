//
// Created by McRebel on 09.05.2022.
//

#ifndef MSE2_ROBOTER_SENSOR_H
#define MSE2_ROBOTER_SENSOR_H

#include <random>



class Sensor {
public:
    virtual ~Sensor(){};
    virtual int checkSensor() = 0;

};

class Distancesensor: public Sensor {
public:
    virtual int checkSensor() override;
};

class Cliffsensor: public Sensor {
public:
    virtual int checkSensor() override;
};

class Camerasensor: public Sensor {
public:
    virtual int checkSensor() override;
};


#endif //MSE2_ROBOTER_SENSOR_H
