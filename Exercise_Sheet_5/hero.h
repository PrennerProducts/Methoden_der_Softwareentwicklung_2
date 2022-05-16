

#ifndef HERO_H_
#define HERO_H_


#include <string>
#include "character.h"
#include "item.h"
#include <iostream>

// forward declaration
class NPC;


#define HERO_INVENTORY_SIZE		10
#define HERO_GEAR_SIZE			2


class Hero : public Character {
protected:
	Item* gear[HERO_GEAR_SIZE];

public:
	Hero(const std::string& name, int health, int gold,
			int armor, int magicResistance);

	virtual ~Hero();

	virtual void attack(Character* enemy) override;

	bool fight(NPC* enemy);

	void sellItem(int index);

	int addGearItem(Item* item);

	Item* removeGearItem(int slot);
};

std::ostream& operator<<(std::ostream& out, const Hero& hero);


#endif /* HERO_H_ */
