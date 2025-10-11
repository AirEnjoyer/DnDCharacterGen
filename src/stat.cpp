#include "stat.hpp"
#include "ClearScreen.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

stat::stat(std::string Name) {
  name = Name;
  score = 0;
  modifier = 0;
}

void stat::pickStat(std::vector<int> &rolls) {
  ClearScreen();
  std::cout << "What would you like to assign to " << name
            << "? Pick by number (first option is one, second is 2, etc.)"
            << std::endl;
  for (int currentRoll : rolls) {
    std::cout << currentRoll << std::endl;
  }
  int choice;
  std::cin >> choice;
  choice--;
  score = rolls[choice];
  modifier = ((score - 10) / 2);
  rolls.erase(rolls.begin() + choice);
};

int stat::returnScore() { return score; }

int stat::returnModifier() { return modifier; }

stat Strength("Strength");
stat Dexterity("Dexterity");
stat Constitution("Constitution");
stat Wisdom("Wisdom");
stat Intelligence("Intelligence");
stat Charisma("Charisma");

void genStats(std::vector<int> &rolls) {
  for (int i = 0; i <= 5; i++) {
    std::vector<int> tempRolls;
    for (int i = 0; i < 4; i++) {
      tempRolls.push_back((rand() % 6) + 1);
    }
    int statSum = std::accumulate(tempRolls.begin(), tempRolls.end(), 0);
    auto lowestRoll = std::min_element(tempRolls.begin(), tempRolls.end());
    statSum -= *lowestRoll;
    rolls.push_back(statSum);
    tempRolls.erase(tempRolls.begin(), tempRolls.end());
    std::sort(rolls.begin(), rolls.end(), std::greater<int>());
  }
}
