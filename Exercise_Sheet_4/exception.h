//
// Created by McRebel on 19.04.2022.
//

#ifndef MSE2_EXERCISE_SHEET_4_EXCEPTION_H
#define MSE2_EXERCISE_SHEET_4_EXCEPTION_H

#include <stdexcept>

class GameException: public std::runtime_error{
public:
    using std::runtime_error::runtime_error;
};

class InvalidIndexException : public GameException{
public:
    using GameException::GameException;
};

class InventoryFullException : public GameException{
public:
    using GameException::GameException;
};

class GearFullException : public GameException{
public:
    using GameException::GameException;
};

class InvalidItemException : public GameException{
public:
    using GameException::GameException;
};

class InvalidArgumentException : public GameException{
public:
    using GameException::GameException;
};

class InvalidValueException : public GameException{
public:
    using GameException::GameException;
};



#endif //MSE2_EXERCISE_SHEET_4_EXCEPTION_H
