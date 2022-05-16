//
// Created by McRebel on 20.02.2022.
//

#include <iostream>
#include "hero.h"
#include "character.h"
#include <cstdlib>
#include <experimental/random>

void attack(struct Hero_t *hero, struct Character_t *enemy) {
    //int randvalue = 15 + std::rand() % 25 ;
    int randvalue = std::experimental::randint(15, 35);
    enemy->livepoints -= randvalue;
    std::cout << hero->name << " trifft " << enemy->name << " fuer " << randvalue << " Lebenspunkte!" << std::endl;
}

void sellItem(struct Hero_t *hero, int index) {
    if(hero->items[index].isValid){
        hero->gold +=  hero->items[index].value;
        hero->items[index].isValid = false;
        std::cout << "Gegenstand " << hero->items[index].label << " wurde verkauft." << hero->name << " besitzt nun " << hero->gold << " Gold." << std::endl;
    } else{
        std::cout << "Der Gegenstand " << hero->items[index].label << " befindet sich nicht im Inventar und kann daher nicht verkauft werden!";
    }
}

bool check_death(Hero_t* hero){
    if(hero->livepoints <=0){
        return true;
    }
    else{
        return false;
    }
}

bool check_death(Character_t* enemy){
    if(enemy->livepoints <=0){
        return true;
    }
    else{
        return false;
    }
}

bool fight(Hero_t *hero, Character_t *enemy) {
    while (true){
        attack(hero, enemy);
        if(check_death(enemy)){
            std::cout << enemy->name << " fiel in Ohmacht! " << hero->name << " hat noch " << hero->livepoints << " Lebenspunkte uebrig!" << std::endl;
            return true;
        }
        else {
            attack(enemy, hero);
            if (check_death(hero)) {
                std::cout << hero->name << " fiel in Ohmacht! GAME OVER!";
                return false;
            }
        }
    }
}

void initHero(Hero_t *hero, char *name, int health, int gold) {
    hero->name = name;
    hero->livepoints = health;
    hero->gold = gold;
    for (int i = 0; i < 10; ++i) {
        hero->items[i].isValid = false;
    }

}
