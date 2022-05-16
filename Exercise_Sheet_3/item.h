//
// Created by McRebel on 22.03.2022.
//

#ifndef MSE2_EXERCISE_SHEET_3_ITEM_H
#define MSE2_EXERCISE_SHEET_3_ITEM_H
#include <string>


class Item {
private:
    std::string name;
    int gold;
    bool valid;

public:
    void initItem(const std::string& name, int gold);

    void initItem();

    // Getter & Setter

    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
    }

    bool isValid() const {
        return valid;
    }

    void setValid(bool valid) {
        this->valid = valid;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if (!name.empty()) {
            this->name = name;
        }
    }
};


#endif //MSE2_EXERCISE_SHEET_3_ITEM_H
