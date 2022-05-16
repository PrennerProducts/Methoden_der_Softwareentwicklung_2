
#include "npc.h"


Item* NPC::retrieveRandomLoot() {
    Item* item;
    for (int i = 0; i < 10; i++) {
        int dice = std::rand() % CHARACTER_INVENTORY_SIZE;
        item = removeInventarItem(dice);
        if (item) {
            break;
        }
    }
    if(!item){
        throw InvalidItemException("npc:retriveRandomLoot() Invalid Item");
    }
    return item;
}
