//
// Created by McRebel on 01.03.2022.
//

#ifndef MSE2_EXERCISE_SHEET_2_ITEM_H
#define MSE2_EXERCISE_SHEET_2_ITEM_H

#include <string>

class Item {
private:
    std::string label;
    int value = 0;
    bool isValid = false;
public:
    void initItem(std::string name, int gold);
    void initItem();
    bool getIsValid();
    int getValue();
    void setIsValid(bool value);
    void setValue(int value);
    std::string getLabel();

};

#endif //MSE2_EXERCISE_SHEET_2_ITEM_H
