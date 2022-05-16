//
// Created by McRebel on 20.02.2022.
//

#ifndef EXERCISE_1_HERO_H
#define EXERCISE_1_HERO_H


#include <string>
#include "character.h"
#include "hero.h"



struct Hero_t {
    std::string name;
    int livepoints = 0;
    int gold = 0;
    Item_t items[10];

};

void attack(Hero_t* hero, struct Character_t* enemy);
void sellItem(Hero_t* hero, int index);
bool fight(Hero_t* hero, struct Character_t* enemy);
void initHero(Hero_t* hero, char* name, int health, int gold);



#endif //EXERCISE_1_HERO_H
