//
// Created by McRebel on 20.02.2022.
//

#include <iostream>
#include <experimental/random>
#include "character.h"
#include "hero.h"

void attack(Character_t *character, Hero_t *hero) {
    //int randvalue = rand() % 26 + 15;
    //int randvalue = 5+ std::rand() % 15;
    int randvalue = std::experimental::randint(5, 15);
    hero->livepoints -= randvalue;
    std::cout << character->name << " trifft " << hero->name << " fuer " << randvalue << " Lebenspunkte!" << std::endl;
}

void initCharacter(Character_t *character, char *name, int health, int gold) {
    character->name = name;
    character->livepoints = health;
    character->gold = gold;
    for (int i = 0; i < 10; ++i) {
        character->items->isValid = false;
    }
}
