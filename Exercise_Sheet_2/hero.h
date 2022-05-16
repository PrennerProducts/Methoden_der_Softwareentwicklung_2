#ifndef MSE2_EXERCISE_SHEET_2_HERO_H
#define MSE2_EXERCISE_SHEET_2_HERO_H

#include <string>

#include "character.h"


class Hero {
private:
    std::string name;
    int livepoints = 0;
    int gold = 0;
    Item items[10];
    Item equipment[2];
public:
    void attack(class Character& enemy);
    void sellItem(int index);
    bool check_death();
    bool check_death(class Character& enemy);
    bool fight(class Character& enemy);
    void initHero(const std::string name, int health, int gold);
    int getLivepoints();
    void setLivepoints(int livepoints);
    int getgold();

    std::string getName();
    int getGold();
    void setGold(int gold);

    int addInventarItem(const Item& item);
    int addEquipmentItem(const Item& item);
    Item removeInventarItem(int slot);
    Item removeEquipmentItem(int slot);
    Item* getInventory(int index);

};


#endif //MSE2_EXERCISE_SHEET_2_HERO_H
