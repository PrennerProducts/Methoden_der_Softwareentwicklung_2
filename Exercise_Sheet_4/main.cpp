
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"


int main() {
    try {
        std::srand(time(0));

        Hero heldin("Annina", 300, 100, 0, 0);

        Sorcerer pascal("Pascal", 50, 10000, 0, 0, 0);
        pascal.addInventarItem(new Item("Diamand", 1000));
        pascal.addInventarItem(new Item("Zauberstab", 100));

        Fighter matthias("Matthias", 50, 10000, 0, 0, 0);
        matthias.addInventarItem(new Item("Rubin", 800));
        matthias.addInventarItem(new Item("Schwert", 200));

        if (heldin.fight(&pascal)) {
            heldin.fight(&matthias);
        }

        if (heldin.getHealth() > 0) {
            for (int i = 0; i < HERO_INVENTORY_SIZE; i++) {
                heldin.sellItem(i);
            }
        }

    }catch (std::exception &e){
        std::cerr << "cought exception in Main: " << e.what() << std::endl;
    }
}

