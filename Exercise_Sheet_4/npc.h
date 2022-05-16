//
// Created by McRebel on 16.04.2022.
//

#ifndef MSE2_EXERCISE_SHEET_4_NPC_H
#define MSE2_EXERCISE_SHEET_4_NPC_H

#include "character.h"
#include "item.h"


class NPC : public Character {
public:
    using Character::Character;

    virtual ~NPC() {
        if (health > 0) {
            std::cout << *this << " verabschiedet sich und reitet in den Sonnenuntergang" << std::endl;
        } else {
            std::cout << *this << " liegt weiter ohnmächtig am Boden" << std::endl;
        }
    }

    Item* retrieveRandomLoot();
};


#endif //MSE2_EXERCISE_SHEET_4_NPC_H
