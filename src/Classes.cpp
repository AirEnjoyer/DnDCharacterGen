#include "Class.hpp"
#include "Clear.hpp"
#include <iostream>
#include <string>
#include <vector>

Class::Class(std::string className, int hitDiceType, int save1, int save2) {
  name = className;
  hitDiceMaxRoll = hitDiceType;
  for (int i = 0; i < 6; i++) {
    savingThrows.push_back(false);
  }
  savingThrows[save1] = true;
  savingThrows[save2] = true;
}

bool Class::returnIsProficient(int index) { return savingThrows[index]; }
int Class::returnHitDice() { return hitDiceMaxRoll; }
std::string Class::returnClassName() { return name; }

std::vector<Class> classes{
    Class("Barbarian", 12, 0, 2), Class("Bard", 8, 1, 5),
    Class("Cleric", 8, 3, 5),     Class("Druid", 8, 3, 4),
    Class("Fighter", 10, 0, 2),   Class("Monk", 8, 0, 1),
    Class("Paladin", 8, 3, 5),    Class("Ranger", 10, 0, 1),
    Class("Rogue", 8, 1, 4),      Class("Sorcerer", 6, 2, 5),
    Class("Warlock", 8, 3, 5),    Class("Wizard", 6, 3, 4)};

int classPicked;

void pickClass() {
  clearScreen();
  for (int i = 0; i < classes.size(); i++) {
    std::cout << i + 1 << ". " << classes[i].returnClassName() << std::endl;
  }

  std::cin >> classPicked;
}
