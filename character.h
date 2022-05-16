//
// Created by McRebel on 20.02.2022.
//

#ifndef EXERCISE_1_CHARACTER_H
#define EXERCISE_1_CHARACTER_H


#include <string>
#include "item.h"
#include "hero.h"
#include "character.h"

struct Character_t {
    std::string name;
    int livepoints = 0;
    int gold = 0;
    Item_t items[10];
};

void attack(Character_t* character, struct Hero_t* hero);
void initCharacter(Character_t* character, char* name, int health, int gold);



#endif //EXERCISE_1_CHARACTER_H
