#include "item.h"




void Item::initItem(const std::string& name, int gold) {
    this->name = name;
    this->gold = gold;
    this->valid = true;
}

void Item::initItem() {
    this->valid = false;
}

