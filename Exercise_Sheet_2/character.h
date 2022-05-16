//
// Created by McRebel on 01.03.2022.
//

#ifndef MSE2_EXERCISE_SHEET_2_CHARACTER_H
#define MSE2_EXERCISE_SHEET_2_CHARACTER_H

#include <string>
#include "item.h"
#include "hero.h"
#include "character.h"

class Character {
private:
    std::string name;
    int livepoints = 0;
    int gold = 0;
    Item items[10];
    Item equipment[2];
public:
    void attack(class Hero& hero);
    void initCharacter(const std::string& name, int health, int gold);
    int getLivepoints();
    void setLivepoints(int livepoints);
    bool checkDeath();
    std::string getName();
    int addInventarItem(const Item& item);
    Item* removeInventarItem(int slot);
};



#endif //MSE2_EXERCISE_SHEET_2_CHARACTER_H
