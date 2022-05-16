
#include "character.h"
#include <iostream>



Character::Character(const std::string& name, int health, int gold,
                     int armor, int magicResistance)
        : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance), inventory() {
    if (name.length() <= 0){
        throw InvalidArgumentException("Characker::Charackter() Invalid Argument");
    }
    if (health <= 0 || gold < 0 || armor < 0 || magicResistance < 0){
        throw InvalidValueException("Charackter::Charackter() Invalid Value");
    }
}

int Character::addInventarItem(Item* item) {
    if (item) {
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
            if (!inventory[i]) {
                inventory[i] = item;
                return i;
            }
        }
        throw InventoryFullException("Charackter::addInventarItem Inventary ist Full!");
    }
    else{
        throw InvalidItemException("Characker::addInventarItem Invalid Item");
    }
    return -1;
}

Item* Character::removeInventarItem(int slot) {
    if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE) {
        Item* retval = inventory[slot];
        inventory[slot] = nullptr;
        return retval;
    }else{
        throw InvalidIndexException("Characker::removeInventarItem Invalid Index");
    }

    //Item* retval = nullptr;
    return nullptr;
}

std::ostream& operator<<(std::ostream& out, const Character& ch) {
    out << ch.getName();
    return out;
}
