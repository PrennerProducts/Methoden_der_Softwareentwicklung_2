//
// Created by McRebel on 20.02.2022.
//

#include "item.h"
#include <iostream>

void initItem(Item_t *ITEM, char *name, int gold) {
    ITEM->label = name;
    ITEM->value = gold;
    ITEM->isValid = true;
}

void initItem(Item_t *gegenstand) {
    gegenstand->isValid = false;

}
