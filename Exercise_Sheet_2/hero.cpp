#include <iostream>
#include "hero.h"
#include "character.h"
#include <cstdlib>
#include <experimental/random>


    void Hero::attack(Character& enemy) {
        //int randvalue = 15 + std::rand() % 25 ;
        int randvalue = std::experimental::randint(15, 35);
        int enemyPoints = enemy.getLivepoints();
        enemy.setLivepoints(enemyPoints-randvalue);

        std::cout << this->name << " trifft " << enemy.getName() << " fuer " << randvalue << " Lebenspunkte!" << std::endl;
    }

    void Hero::sellItem(int index) {
        if (this->items[index].getIsValid()) {

            int mygold = this->getGold() + this->items[index].getValue();
            this->setGold(mygold);
            this->items[index].setIsValid(false);
            std::cout << "Gegenstand " << this->items[index].getLabel() << " wurde verkauft." << this->getName()
                      << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        } else {
            std::cout << "Der Gegenstand " << this->items[index].getLabel()
                      << " befindet sich nicht im Inventar und kann daher nicht verkauft werden!";
        }
    }

    bool Hero::check_death() {
        if (this->livepoints <= 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Hero::check_death(Character& enemy) {
        if (enemy.getLivepoints() <= 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Hero::fight(class Character& enemy) {
        while (true) {
            Hero::attack(enemy);
            if (check_death(enemy)) {
                std::cout << enemy.getName() << " fiel in Ohmacht! " << this->getName() << " hat noch " << this->getLivepoints()
                          << " Lebenspunkte uebrig!" << std::endl;
                return true;
            } else {
                enemy.attack(*this);
                if (check_death()) {
                    std::cout << this->getName() << " fiel in Ohmacht! GAME OVER!";
                    return false;
                }
            }
        }
    }

    void Hero::initHero(const std::string name, int health, int gold) {
        this->name = name;
        this->livepoints = health;
        this->gold = gold;
        for (int i = 0; i < 10; ++i) {
            this->items[i].setIsValid(false);
        }

    }

int Hero::getLivepoints() {
    return this->livepoints;
}

void Hero::setLivepoints(int livepoints) {
    this->livepoints = livepoints;
}



std::string Hero::getName() {
    return this->name;
}

int Hero::getGold() {
    return this->gold;
}

int Hero::addInventarItem(const Item &item) {
    for (int i = 0; i < 10; ++i) {
        if(!this->items[i].getIsValid()){
            this->items[i] = item;
            this->items->setIsValid(true);
            return i;
        }
    }
    return -1;
}

int Hero::addEquipmentItem(const Item& item) {
    for (int i = 0; i < 2; ++i) {
        if(!this->equipment[i].getIsValid()){
            this->equipment[i] = item;
            return i;
        }
    }
    return -1;
}

Item Hero::removeInventarItem(int slot){
    if(slot >0 && slot <10 && this->items->getIsValid()){
       this->items[slot].initItem();
        return this->items[slot];
    }
    return this->items[slot];
}

Item Hero::removeEquipmentItem(int slot) {
    if(slot >0 && slot <10 && this->equipment->getIsValid()){
        this->items[slot].initItem();
        return this->items[slot];
    }
    return this->items[slot];
}

Item *Hero::getInventory(int index) {
    if (index >= 10 || index < 0 || ! this->items[index].getIsValid()){
        return nullptr;
    }
    else{
        return &(this->items[index]);
    }
}

int Hero::getgold() {
    return this->gold;
}

void Hero::setGold(int mygold) {
    this->gold = mygold;
}
