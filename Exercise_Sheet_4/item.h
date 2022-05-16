//
// Created by McRebel on 16.04.2022.
//

#ifndef MSE2_EXERCISE_SHEET_4_ITEM_H
#define MSE2_EXERCISE_SHEET_4_ITEM_H

#include <string>
#include <iostream>
#include "exception.h"

class Item {
private:
    std::string name;
    int gold;
    bool valid;

public:
    Item(const std::string& name, int gold);

    Item();

    // Getter & Setter

    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
        throw InvalidValueException("Item::setGold() Invalid Value");
    }


    const std::string& getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if (!name.empty()) {
            this->name = name;
        }
        throw InvalidValueException("item:setName() Invalid Value");
    }
};

std::ostream& operator<<(std::ostream& out, const Item& item);



#endif //MSE2_EXERCISE_SHEET_4_ITEM_H
