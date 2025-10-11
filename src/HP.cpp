#include "HP.hpp"
#include <cstdlib>
#include <iostream>

void getHP(int &MaxHP, int &characterLevel, int &hitDice) {
  std::cout << "Do you want to roll for HP? (Y or N)" << std::endl
            << std::flush;
  char choice;
  std::cin >> choice;
  MaxHP = hitDice;
  if (choice == 'Y' || choice == 'y') {
    for (int i = 0; i < characterLevel - 1; i++) {
      MaxHP += ((rand() % hitDice) + 1);
    }
  } else {
    for (int i = 0; i < characterLevel - 1; i++) {
      MaxHP += hitDice / 2;
    }
  }
}
