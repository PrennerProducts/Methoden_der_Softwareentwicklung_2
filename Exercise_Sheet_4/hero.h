//
// Created by McRebel on 16.04.2022.
//

#ifndef MSE2_EXERCISE_SHEET_4_HERO_H
#define MSE2_EXERCISE_SHEET_4_HERO_H



#include <string>
#include "character.h"
#include "item.h"
#include <iostream>

// forward declaration
class NPC;


#define HERO_INVENTORY_SIZE		10
#define HERO_GEAR_SIZE			2


class Hero : public Character {
protected:
    Item* gear[HERO_GEAR_SIZE];

public:
    Hero(const std::string& name, int health, int gold,
         int armor, int magicResistance);

    virtual ~Hero() {
        std::cout << *this << " verabschiedet sich und reitet in den Sonnenuntergang" << std::endl;
        for (int i = 0; i < HERO_GEAR_SIZE;  ++i) {
            delete gear[i];
        }
    }

    virtual void attack(Character* enemy) override;

    bool fight(NPC* enemy);

    void sellItem(int index);

    int addGearItem(Item* item);

    Item* removeGearItem(int slot);
};

std::ostream& operator<<(std::ostream& out, const Hero& hero);



#endif //MSE2_EXERCISE_SHEET_4_HERO_H
