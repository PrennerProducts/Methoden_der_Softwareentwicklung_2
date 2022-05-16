
#include "character.h"
#include <iostream>
#include <cstring>
#include "exceptions.h"


Character::Character(const std::string& name, int health, int gold,
		int armor, int magicResistance)
		: name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {
	std::memset(inventory, 0, sizeof(Item*)*CHARACTER_INVENTORY_SIZE);
}


Character::~Character() {
	for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
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
	}
	throw InventoryFullException();
}

Item* Character::removeInventarItem(int slot) {
	if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE) {
		if (!inventory[slot]) {
			throw InventoryEmptySlotException();
		}
		Item* retval = inventory[slot];
		inventory[slot] = nullptr;
		return retval;
	}
	throw InvalidIndexException();
}

std::ostream& operator<<(std::ostream& out, const Character& ch) {
	out << ch.getName();
	return out;
}



