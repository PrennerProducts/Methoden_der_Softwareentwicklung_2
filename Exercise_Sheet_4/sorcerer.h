//
// Created by McRebel on 16.04.2022.
//

#ifndef MSE2_EXERCISE_SHEET_4_SORCERER_H
#define MSE2_EXERCISE_SHEET_4_SORCERER_H


#include "npc.h"
#include <iostream>

class Sorcerer : public NPC {
protected:
    int magicPower;

public:
    Sorcerer(const std::string& name, int health, int gold,
             int armor, int magicResistance, int magicPower)
            : NPC(name, health, gold, armor, magicResistance), magicPower(magicPower) {
        if(magicPower < 0){
            throw InvalidValueException("sourcerer:Sorcerer()::magicPower() Invalid Value");
        }
    }

    virtual void attack(Character* hero) override;

    // Getter & Setter

    int getMagicPower() const {
        return magicPower;
    }

    void setMagicPower(int magicPower) {
        if (magicPower >= 0) {
            this->magicPower = magicPower;
        } else{
            throw InvalidValueException("sourcerer:setMagicPower() Invalid Value");
        }
    }
};

std::ostream& operator<<(std::ostream& out, const Sorcerer& s);

#endif //MSE2_EXERCISE_SHEET_4_SORCERER_H
