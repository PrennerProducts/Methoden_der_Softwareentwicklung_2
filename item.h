//
// Created by McRebel on 20.02.2022.
//

#ifndef EXERCISE_1_ITEM_H
#define EXERCISE_1_ITEM_H


#include <string>

struct Item_t {
    std::string label;
    int value = 0;
    bool isValid = false;

};

void initItem(Item_t* ITEM, char* name, int gold);
void initItem(Item_t* gegenstand);


#endif //EXERCISE_1_ITEM_H
