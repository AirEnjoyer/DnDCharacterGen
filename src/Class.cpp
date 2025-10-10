#include "ClearScreen.hpp"
#include "Class.hpp"
#include <iostream>
#include <vector>
#include <string>

Class::Class(std::string name, int hitDiceType, int save1, int save2){
  className = name;
  for (int i = 0; i <= 5; i++){
    saves.push_back(false);
  }
  saves[save1] = true;
  saves[save2] = true;
  hitDiceMaxRoll = hitDiceType;
};

std::string Class::returnName(){
  return className;
}

int Class::returnHitDice(){
  return hitDiceMaxRoll;
}

bool Class::returnSave(int index){
  return saves[index];
}

std::vector<Class> classes = {
  Class("Barbarian", 12, 0, 2),
  Class("Bard", 8, 1, 5),
  Class("Cleric", 8, 3, 5),
  Class("Druid", 8, 4, 5),
  Class("Fighter", 10, 0, 2),
  Class("Monk", 8, 0, 1 ),
  Class("Paladin", 10, 3, 5),
  Class("Ranger", 10, 0, 1),
  Class("Rogue", 8, 1, 4),
  Class("Sorcerer", 6, 2, 5),
  Class("Warlock", 8, 3, 5),
  Class("Warlock", 8, 3, 4),
};
