

#include "npc.h"
#include "exceptions.h"


Item* NPC::retrieveRandomLoot() {
	Item* item = nullptr;
	for (int i = 0; i < 10; i++) {
		int dice = std::rand() % CHARACTER_INVENTORY_SIZE;
		try {
			item = removeInventarItem(dice);
			break;
		} catch(InventoryEmptySlotException& e) {
		}
	}
	if (!item) {
		throw InvalidLoot();
	}
	return item;
}




