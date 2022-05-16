
#include <iostream>
#include <string>
#include "hero.h"
#include "character.h"
#include "item.h"



int main() {
    Hero annina;
    Character mathias;
    Character pascal;
    Item zaubertrank, diamanten, stim, zauberstab;
    zaubertrank.initItem("Zaubertrank", 15);
    diamanten.initItem("Diamanten", 20);
    stim.initItem("Stim",10);
    zauberstab.initItem("Zauberstab", 20);



    annina.initHero("Annina", 300, 0);
    mathias.initCharacter("Mathias", 50, 0);
    pascal.initCharacter("Pascal", 100, 0);


    annina.fight(mathias);
    if (annina.getLivepoints() >= 0){
        for (int i = 0; i <10;i++){
            if (annina.getInventory(i)==nullptr){
                annina.addInventarItem(zaubertrank);
                std::cout << "Gegenstand " << annina.getInventory(i)->getLabel() << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
                break;
            }
        }
    }
    annina.fight(pascal);
    if (annina.getLivepoints() >= 0){
        for (int i = 0; i <10;i++){
            if (annina.getInventory(i)==nullptr){
                annina.addInventarItem(diamanten);
                std::cout << "Gegenstand " << annina.getInventory(i)->getLabel() << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
                break;
            }
        }
    }
    if (annina.getLivepoints() >= 0){
        for (int i = 0; i <10;i++){
            if (annina.getInventory(i)!=nullptr) {
                std::string myitem_name =  annina.getInventory(i)->getLabel();
                annina.sellItem(i);

                annina.removeInventarItem(i);
            }
        }
    }
    return 0;
}