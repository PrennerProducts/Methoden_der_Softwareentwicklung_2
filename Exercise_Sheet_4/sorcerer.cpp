
#include "sorcerer.h"



void Sorcerer::attack(Character* enemy) {
    int damage = 5 + std::rand() % 6 + magicPower - enemy->getMagicResistance();
    if (damage < 0) {
        damage = 0;
    }
    enemy->setHealth(enemy->getHealth() - damage);
}


std::ostream& operator<<(std::ostream& out, const Sorcerer& s) {
    out << "Zauberer " << s.getName();
    return out;
}


