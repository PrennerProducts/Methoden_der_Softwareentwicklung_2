
#ifndef CHARACTER_H_
#define CHARACTER_H_


#include <string>
#include "item.h"
#include "exceptions.h"

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

	virtual ~Character();

	virtual void attack(Character* hero) = 0;

	int addInventarItem(Item* item);

	Item* removeInventarItem(int slot);

	// Getter & Setter

	Item* getInventory(int slot) {
		if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE) {
			if (!inventory[slot]) {
				throw InventoryEmptySlotException();
			}
			return inventory[slot];
		} else {
			throw InvalidIndexException();
		}
	}

	int getGold() const {
		return gold;
	}

	void setGold(int gold) {
		if (gold >= 0) {
			this->gold = gold;
		} else {
			throw InvalidArgumentException("Gold may not be negative");
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
		} else {
			throw InvalidArgumentException("Name may not be empty");
		}
	}

	int getArmor() const {
		return armor;
	}

	void setArmor(int armor) {
		if (armor >= 0) {
			this->armor = armor;
		} else {
			throw InvalidArgumentException("Armor may not be negative");
		}
	}

	int getMagicResistance() const {
		return magicResistance;
	}

	void setMagicResistance(int magicResistance) {
		if (magicResistance >= 0) {
			this->magicResistance = magicResistance;
		} else {
			throw InvalidArgumentException("Magic Resistance may not be negative");
		}
	}
};


std::ostream& operator<<(std::ostream& out, const Character& ch);




#endif /* CHARACTER_H_ */
