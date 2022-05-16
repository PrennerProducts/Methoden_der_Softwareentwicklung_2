

#include "hero.h"
#include <cstdlib>
#include <iostream>
#include "character.h"
#include "npc.h"
#include <cstring>


Hero::Hero(const std::string& name, int health, int gold,
		int armor, int magicResistance)
		: Character(name, health, gold, armor, magicResistance) {
	std::memset(gear, 0, sizeof(Item*)*HERO_GEAR_SIZE);
}

Hero::~Hero() {
	for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
	}
	std::cout << *this << " verabschiedet sich und reitet in den Sonnenuntergang" << std::endl;
}

void Hero::attack(Character* enemy) {
	int damage = 15 + std::rand() % 11 - enemy->getArmor();
	if (damage < 0) {
		damage = 0;
	}
	std::cout << *this << " trifft " << *enemy << " fuer " << damage << " Lebenspunkte!" << std::endl;
	enemy->setHealth(enemy->getHealth() - damage);
}


void Hero::sellItem(int index) {
	if (index >= 0 && index < HERO_INVENTORY_SIZE) {
		if (inventory[index]) {
			gold += inventory[index]->getGold();
			std::cout << *inventory[index] << " wurde verkauft. "
					<< *this << " besitzt nun " << gold << " Gold." << std::endl;
			inventory[index] = nullptr;
		} else {
			throw InventoryEmptySlotException();
		}
	} else {
		throw InvalidIndexException();
	}
}

bool Hero::fight(NPC* enemy) {
	while (health > 0 && enemy->getHealth() > 0) {
		attack(enemy);
		if (enemy->getHealth() > 0) {
			enemy->attack(this);
		}
	}
	if (health > 0) {
		std::cout << *enemy << " fiel in Ohnmacht! " << name
				<< " hat noch " << health << " Lebenspunkte uebrig!" << std::endl;
		try {
			Item* item = enemy->retrieveRandomLoot();
			try {
				addInventarItem(item);
				std::cout << *item << " wurde zum Inventar von "
						<< *this << " hinzugefuegt." << std::endl;
			} catch(InventoryFullException& e) {
				std::cout << "Kein Platz mehr vorhanden!" << std::endl;
			}
		} catch(InvalidLoot& e) {
		}
	}
	return health > 0;
}



int Hero::addGearItem(Item* item) {
	if (item) {
		for (int i = 0; i < HERO_GEAR_SIZE; i++) {
			if (!gear[i]) {
				gear[i] = item;
				return i;
			}
		}
	}
	throw InventoryFullException();
}

Item* Hero::removeGearItem(int slot) {
	if (slot >= 0 && slot < HERO_GEAR_SIZE) {
		if (!gear[slot]) {
			throw InventoryEmptySlotException();
		}
		Item* retval = gear[slot];
		gear[slot] = nullptr;
		return retval;
	}
	throw InvalidIndexException();
}

std::ostream& operator<<(std::ostream& out, const Hero& hero) {
	out << "Heldin " << hero.getName();
	return out;
}
