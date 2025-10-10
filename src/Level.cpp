#include "Level.hpp"
#include <iostream>

void getLevel(int &characterLevel){
  std::cout << "Enter your character level (1-20) " << std::endl;
  std::cin >> characterLevel;
  if (characterLevel < 1){
    characterLevel = 1;
  } else if (characterLevel > 20){
    characterLevel = 20;
  }
}

void getProficiency(int &characterLevel, int &proficiencyBonus){
  if (characterLevel < 5){
    proficiencyBonus = 2;
  } else if (characterLevel < 9){
    proficiencyBonus = 3;
  } else if (characterLevel < 13){
    proficiencyBonus = 4;
  } else if (characterLevel < 17){
    proficiencyBonus = 5;
  } else if (characterLevel <= 20){
    proficiencyBonus = 6;
  }
}
