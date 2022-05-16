//
// Created by McRebel on 01.03.2022.
//

#include "item.h"
#include "hero.h"



void Item::initItem(std::string name, int gold) {
    this->label = name;
    this->value = gold;
    this->isValid = true;
}

void Item::initItem(){
    this->isValid = false;
}

void Item::setIsValid(bool value) {
    this->isValid = value;
}

bool Item::getIsValid() {
    return this->isValid;
}

int Item::getValue() {
    return this->value;
}

void Item::setValue(int value) {
    this->value = value;

}

std::string Item::getLabel() {
    return this->label;
}






