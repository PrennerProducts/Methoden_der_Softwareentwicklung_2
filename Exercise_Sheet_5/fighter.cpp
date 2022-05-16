
#include "fighter.h"



void Fighter::attack(Character* enemy) {
	int damage = 5 + std::rand() % 6 + strength - enemy->getArmor();
	if (damage < 0) {
		damage = 0;
	}
	enemy->setHealth(enemy->getHealth() - damage);
}

std::ostream& operator<<(std::ostream& out, const Fighter& f) {
	out << "Kaempfer " << f.getName();
	return out;
}


