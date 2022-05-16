//
// Created by McRebel on 09.05.2022.
//

#ifndef MSE2_ROBOTER_ROBOTEXCEPTION_H
#define MSE2_ROBOTER_ROBOTEXCEPTION_H

#include <stdexcept>


class RobotException : public std::runtime_error{
public:
    using std::runtime_error::runtime_error;
};



class InvalidMotorspeedException : public RobotException{
public:
    using RobotException::RobotException;
};

class CriticalDangerException : public RobotException{
public:
    using RobotException::RobotException;
};

class InternalErrorExceptionn : public RobotException{
public:
    using RobotException::RobotException;
};

class InvalidStatusExceptoin : public RobotException{
public:
    using RobotException::RobotException;
};


#endif //MSE2_ROBOTER_ROBOTEXCEPTION_H
