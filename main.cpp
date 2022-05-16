#include <iostream>
#include <string>
#include "hero.h"
#include "character.h"



int main() {
    Hero_t annina;
    Character_t mathias;
    Character_t pascal;
    Item_t zaubertrank, schwert;
    initItem(&zaubertrank, (char*)"Zaubertrank", 15);
    initItem(&schwert, (char*)"Schwert", 15);


    initHero(&annina, (char*) "Annina", 300, 0);

    initCharacter(&mathias, (char*) "Mathias", 50, 0);
    initCharacter(&pascal, (char*) "Pascal", 100, 0);


    fight(&annina, &mathias);
    annina.items[1] = zaubertrank;
    std::cout << "Gegenstand " << annina.items[1].label << " wurde zum Inventar der Heldin hinzugefuegt!"<< std::endl;
    fight(&annina, &pascal);
    annina.items[2] = schwert;
    std::cout << "Gegenstand " << annina.items[2].label << " wurde zum Inventar der Heldin hinzugefuegt!"<< std::endl;
    sellItem(&annina, 1);
    sellItem(&annina, 2);




    return 0;
}
