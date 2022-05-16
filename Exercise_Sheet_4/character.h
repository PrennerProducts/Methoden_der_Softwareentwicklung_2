//
// Created by McRebel on 16.04.2022.
//

#ifndef MSE2_EXERCISE_SHEET_4_CHARACTER_H
#define MSE2_EXERCISE_SHEET_4_CHARACTER_H


#include <string>
#include "item.h"
#include "exception.h"

#define CHARACTER_INVENTORY_SIZE	10



class Character {
protected:
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    Item* inventory[CHARACTER_INVENTORY_SIZE];

public:
    Character(const std::string& name, int health, int gold,
              int armor, int magicResistance);

    virtual ~Character() {
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++){
            delete inventory[i];
        }
    }

    virtual void attack(Character* hero) = 0;

    int addInventarItem(Item* item);

    Item* removeInventarItem(int slot);

    // Getter & Setter

    Item* getInventory(int slot) {
        if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE) {
            return inventory[slot];
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
        else{
            throw InvalidArgumentException("Charackter:setGold() Invalid Value");
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
        throw InvalidArgumentException("Charackter:setName() Name empty");

    }

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        if (armor >= 0) {
            this->armor = armor;
        }
        throw InvalidValueException("charackter::setArmor() Invalid Value");
    }

    int getMagicResistance() const {
        return magicResistance;
    }

    void setMagicResistance(int magicResistance) {
        if (magicResistance >= 0) {
            this->magicResistance = magicResistance;
        }
        throw InvalidValueException("charackter::setMagicResistance() Invalid Value");
    }
};


std::ostream& operator<<(std::ostream& out, const Character& ch);



#endif //MSE2_EXERCISE_SHEET_4_CHARACTER_H
