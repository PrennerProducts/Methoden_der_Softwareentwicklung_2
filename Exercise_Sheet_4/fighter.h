//
// Created by McRebel on 16.04.2022.
//

#ifndef MSE2_EXERCISE_SHEET_4_FIGHTER_H
#define MSE2_EXERCISE_SHEET_4_FIGHTER_H


#include "npc.h"
#include <iostream>

class Fighter : public NPC {
protected:
    int strength;

public:
    Fighter(const std::string& name, int health, int gold,
            int armor, int magicResistance, int strength)
            : NPC(name, health, gold, armor, magicResistance), strength(strength) {
        if (strength < 0){
            throw InvalidValueException("fighter::Fighter()::strenght() Invalid Value");
        }

    }

    virtual void attack(Character* enemy) override;

    // Getter & Setter

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        if (strength >= 0) {
            this->strength = strength;
        }
        throw InvalidValueException("fighter:setStranght() Invalid Value");
    }
};

std::ostream& operator<<(std::ostream& out, const Fighter& f);



#endif //MSE2_EXERCISE_SHEET_4_FIGHTER_H
