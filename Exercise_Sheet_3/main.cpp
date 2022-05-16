#include <cstdlib>
#include <iostream>
#include <ctime>
#include "hero.h"
#include "character.h"


int main() {
    std::srand(time(0));

    Hero heldin;
    heldin.initHero("Annina", 300, 100);

    Character pascal;
    pascal.initCharacter("Pascal", 50, 10000);
    Item item1;
    item1.initItem("Diamand", 1000);
    pascal.addInventarItem(item1);
    Item item2;
    item2.initItem("Zauberstab", 100);
    pascal.addInventarItem(item2);
    Item item3;
    item3.initItem("Zauberrobe", 200);
    pascal.addInventarItem(item3);

    Character matthias;
    matthias.initCharacter("Matthias", 100, 1000);
    Item item4;
    item4.initItem("Rubin", 800);
    matthias.addInventarItem(item4);
    Item item5;
    item5.initItem("Schwert", 100);
    matthias.addInventarItem(item5);
    Item item6;
    item6.initItem("Ruestung", 200);
    matthias.addInventarItem(item6);

    if (heldin.fight(&pascal)) {
        heldin.fight(&matthias);
    }

    if (heldin.getHealth() > 0) {
        for (int i = 0; i < HERO_INVENTORY_SIZE; i++) {
            heldin.sellItem(i);
        }
    }
}

