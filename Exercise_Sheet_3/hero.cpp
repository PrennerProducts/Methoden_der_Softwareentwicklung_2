#include "hero.h"
#include <cstdlib>
#include <iostream>
#include "character.h"


void Hero::initHero(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;
    for (int i = 0; i < HERO_INVENTORY_SIZE; i++) {
        inventory[i].initItem();
    }
    for (int i = 0; i < HERO_GEAR_SIZE; i++) {
        gear[i].initItem();
    }
}

void Hero::attack(Character* enemy) {
    int damage = 15 + std::rand() % 11;
    std::cout << name << " trifft " << enemy->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}

void Hero::sellItem(int index) {
    if (index >= 0 && index < HERO_INVENTORY_SIZE) {
        if (inventory[index].isValid()) {
            gold += inventory[index].getGold();
            inventory[index].setValid(false);
            std::cout << "Gegenstand " << inventory[index].getName() << " wurde verkauft. "
                      << name << " besitzt nun " << gold << " Gold." << std::endl;
        }
    }
}

bool Hero::fight(Character* enemy) {
    while (health > 0 && enemy->getHealth() > 0) {
        attack(enemy);
        if (enemy->getHealth() > 0) {
            enemy->attack(this);
        }
    }
    if (health > 0) {
        std::cout << enemy->getName() << " fiel in Ohnmacht! " << name
                  << " hat noch " << health << " Lebenspunkte uebrig!" << std::endl;
        for (int i = 0; i < 10; i++) {
            int dice = std::rand() % CHARACTER_INVENTORY_SIZE;
            Item loot = enemy->removeInventarItem(dice);
            if (loot.isValid()) {
                if (addInventarItem(loot) < 0) {
                    std::cout << "Kein Platz mehr vorhanden!" << std::endl;
                } else {
                    std::cout << loot.getName() << " wurde zum Inventar von "
                              << name << " hinzugefuegt." << std::endl;
                }
                break;
            }
        }
    }
    return health > 0;
}


int Hero::addInventarItem(const Item& item) {
    if (item.isValid()) {
        for (int i = 0; i < HERO_INVENTORY_SIZE; i++) {
            if (!inventory[i].isValid()) {
                inventory[i] = item;
                return i;
            }
        }
    }
    return -1;
}

Item Hero::removeInventarItem(int slot) {
    if (slot >= 0 && slot < HERO_INVENTORY_SIZE) {
        Item retval = inventory[slot];
        inventory[slot].setValid(false);
        return retval;
    }
    Item retval;
    retval.initItem();
    return retval;
}


int Hero::addGearItem(const Item& item) {
    if (item.isValid()) {
        for (int i = 0; i < HERO_GEAR_SIZE; i++) {
            if (!gear[i].isValid()) {
                gear[i] = item;
                return i;
            }
        }
    }
    return -1;
}

Item Hero::removeGearItem(int slot) {
    if (slot >= 0 && slot < HERO_GEAR_SIZE) {
        Item retval = gear[slot];
        gear[slot].setValid(false);
        return retval;
    }
    Item retval;
    retval.initItem();
    return retval;
}