//
// Created by McRebel on 22.03.2022.
//

#ifndef MSE2_EXERCISE_SHEET_3_CHARACTER_H
#define MSE2_EXERCISE_SHEET_3_CHARACTER_H


#include <string>
#include "item.h"

#define CHARACTER_INVENTORY_SIZE	10

// Forward declarations
class Hero;


class Character {
protected:
    std::string name;
    int health;
    int gold;
    Item inventory[CHARACTER_INVENTORY_SIZE];

public:
    void initCharacter(const std::string& name, int health, int gold);

    void attack(Hero* hero);

    int addInventarItem(const Item& item);

    Item removeInventarItem(int slot);

    // Getter & Setter

    Item* getInventory(int slot) {
        if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE) {
            return &inventory[slot];
        } else {
            return nullptr;
        }
    }

    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        if (health < 0) {
            health = 0;
        }
        this->health = health;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if (!name.empty()) {
            this->name = name;
        }
    }
};


#endif //MSE2_EXERCISE_SHEET_3_CHARACTER_H
