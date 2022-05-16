#include "character.h"
#include <iostream>
#include "hero.h"



void Character::initCharacter(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
        inventory[i].initItem();
    }
}

void Character::attack(Hero* hero) {
    int damage = 5 + std::rand() % 11;
    hero->setHealth(hero->getHealth() - damage);
    std::cout << name << " trifft " << hero->getName() << " fuer "
              << damage << " Lebenspunkte!" << std::endl;
}


int Character::addInventarItem(const Item& item) {
    if (item.isValid()) {
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
            if (!inventory[i].isValid()) {
                inventory[i] = item;
                return i;
            }
        }
    }
    return -1;
}

Item Character::removeInventarItem(int slot) {
    if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE) {
        Item retval = inventory[slot];
        inventory[slot].setValid(false);
        return retval;
    }
    Item retval;
    retval.initItem();
    return retval;
}


