
#ifndef MSE2_ROBOTER_MOTOR_H
#define MSE2_ROBOTER_MOTOR_H


class Motor {
public:
    int motorSpeed = 0;
    void setSpeed(int speed);
    int getSpeed();
    void emergencyBrake();

};


#endif //MSE2_ROBOTER_MOTOR_H
