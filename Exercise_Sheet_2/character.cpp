//
// Created by McRebel on 01.03.2022.
//

#include "character.h"
#include <iostream>
#include <experimental/random>
#include "hero.h"
#include "item.h"

void Character::attack(Hero& hero) {
    //int randvalue = rand() % 26 + 15;
    //int randvalue = 5+ std::rand() % 15;
    int randvalue = std::experimental::randint(5, 15);
    int mypoints = hero.getLivepoints();
    mypoints -= randvalue;
    hero.setLivepoints(mypoints);
    std::cout << this->name << " trifft " << hero.getName() << " fuer " << randvalue << " Lebenspunkte!" << std::endl;
}

void Character::initCharacter(const std::string& name, int health, int gold) {
    this->name = name;
    this->livepoints = health;
    this->gold = gold;
    for (int i = 0; i < 10; ++i) {
        this->items->setIsValid(false);
        //this->items->isValid = false;
    }
}

int Character::getLivepoints() {
    return this->livepoints;
}

void Character::setLivepoints(int livepoints) {
    this->livepoints = livepoints;
}

bool Character::checkDeath() {
     return this->livepoints <= 0;
}

std::string Character::getName() {
    return this->name;
}

int Character::addInventarItem(const Item &item) {
    for (int i = 0; i < 10; ++i) {
        if(!this->items[i].getIsValid()){
            this->items[i] = item;
            this->items->setIsValid(true);
            return i;
        }
    }
    return -1;
}

Item *Character::removeInventarItem(int slot) {
    if(slot >0 && slot <10 && this->items->getIsValid()){
        this->items[slot].initItem();
    }
        return nullptr;
}
