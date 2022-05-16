
#ifndef NPC_H_
#define NPC_H_


#include "character.h"
#include "item.h"


class NPC : public Character {
public:
	using Character::Character;

	virtual ~NPC() {
		if (health > 0) {
			std::cout << *this << " verabschiedet sich und reitet in den Sonnenuntergang" << std::endl;
		} else {
			std::cout << *this << " liegt weiter ohnmächtig am Boden" << std::endl;
		}
	}

	Item* retrieveRandomLoot();
};



#endif /* NPC_H_ */
