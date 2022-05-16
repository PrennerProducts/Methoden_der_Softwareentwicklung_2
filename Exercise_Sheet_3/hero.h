//
// Created by McRebel on 22.03.2022.
//

#ifndef MSE2_EXERCISE_SHEET_3_HERO_H
#define MSE2_EXERCISE_SHEET_3_HERO_H
#include <string>
#include "item.h"


#define HERO_INVENTORY_SIZE		10
#define HERO_GEAR_SIZE			2


// forward declaration
class Character;


class Hero {
protected:
    std::string name;
    int health;
    int gold;
    Item inventory[HERO_INVENTORY_SIZE];
    Item gear[HERO_GEAR_SIZE];

public:
    void initHero(const std::string& name, int health, int gold);

    void attack(Character* enemy);

    void sellItem(int index);

    bool fight(Character* enemy);

    int addInventarItem(const Item& item);

    Item removeInventarItem(int slot);

    int addGearItem(const Item& item);

    Item removeGearItem(int slot);


    // Getter & Setter

    Item* getInventory(int slot) {
        if (slot >= 0 && slot < HERO_INVENTORY_SIZE) {
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


#endif //MSE2_EXERCISE_SHEET_3_HERO_H
