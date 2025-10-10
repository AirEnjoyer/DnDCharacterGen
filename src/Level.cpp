#include "Level.hpp"
#include "Clear.hpp"
#include <iostream>

int ProficiencyBonus = 0;
void getLevel() {
  clearScreen();
  std::cout << "Enter your level (1-20)" << std::endl;
  int level;
  std::cin >> level;
  if (level < 1) {
    level = 1;
  } else if (level > 20) {
    level = 20;
  }
  if (level <= 4) {
    ProficiencyBonus += 2;
  } else if (level <= 8) {
    ProficiencyBonus += 3;
  } else if (level <= 12) {
    ProficiencyBonus += 4;
  } else if (level <= 16) {
    ProficiencyBonus += 5;
  } else if (level <= 20) {
    ProficiencyBonus += 6;
  }
}
