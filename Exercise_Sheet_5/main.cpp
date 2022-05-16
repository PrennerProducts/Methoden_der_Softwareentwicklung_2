

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"


int main() {
	std::srand(time(0));

	Hero heldin("Annina", 300, 100, 0, 0);
/*	try {
		heldin.setGold(10);
	} catch(InvalidArgumentException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		heldin.getInventory(5);
	} catch(InvalidIndexException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		heldin.setArmor(10);
	} catch(InvalidArgumentException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		heldin.removeInventarItem(5);
	} catch(InvalidIndexException& e) {
		std::cerr << "Exception caught (handler1): " << e.what() << std::endl;
	} catch(InventoryEmptySlotException& e) {
		std::cerr << "Exception caught (handler2): " << e.what() << std::endl;
	}
	try {
		heldin.removeInventarItem(1);
	} catch(InvalidIndexException& e) {
		std::cerr << "Exception caught (handler1): " << e.what() << std::endl;
	} catch(InventoryEmptySlotException& e) {
		std::cerr << "Exception caught (handler2): " << e.what() << std::endl;
	}*/

	Sorcerer pascal("Pascal", 50, 10000, 0, 0, 0);
	pascal.addInventarItem(new Item("Diamand", 1000));
	pascal.addInventarItem(new Item("Zauberstab", 100));

	Fighter matthias("Matthias", 50, 10000, 0, 0, 0);
	matthias.addInventarItem(new Item("Rubin", 800));
	matthias.addInventarItem(new Item("Schwert", 200));

	if (heldin.fight(&pascal)) {
		heldin.fight(&matthias);
	}

	if (heldin.getHealth() > 0) {
		for (int i = 0; i < HERO_INVENTORY_SIZE; i++) {
			try {
				heldin.sellItem(i);
			} catch(InventoryEmptySlotException& e) {
			}
		}
	}
}





