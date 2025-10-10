#include "stat.hpp"
#include "Clear.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <vector>

stat::stat(std::string Name) {
  name = Name;
  score = 0;
  modifier = 0;
}

void stat::setStat(int Score) {
  score = Score;
  modifier = (score - 10) / 2;
}

std::string stat::returnName() { return name; }
std::vector<int> statRolls;
std::vector<stat> stats = {stat("Strength"),     stat("Dexterity"),
                           stat("Constituion"),  stat("Wisdom"),
                           stat("Intelligence"), stat("Charisma")};

int stat::returnScore() { return score; }

int stat::returnModifier() { return modifier; }

void genStats() {
  std::vector<int> tempRolls;
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j < 4; j++) {
      tempRolls.push_back((rand() % 6) + 1);
    }
    int statSum = std::accumulate(tempRolls.begin(), tempRolls.end(), 0);

    auto lowestRoll = std::min_element(tempRolls.begin(), tempRolls.end());
    statSum -= *lowestRoll;
    statRolls.push_back(statSum);
    tempRolls.erase(tempRolls.begin(), tempRolls.end());
  }
}

void pickStats() {
  for (stat currentStat : stats) {
    clearScreen();
    std::cout << "What would you like to assign to " << currentStat.returnName()
              << std::endl;
    for (int currentRoll : statRolls) {
      std::cout << currentRoll << std::endl;
    }
    int choice;
    std::cin >> choice;
    currentStat.setStat(statRolls[choice - 1]);
  }
}
