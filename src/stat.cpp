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

void pickStats() {
  std::vector<int> tempRolls;
  srand(static_cast<unsigned int>(time(0)));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      tempRolls.push_back((rand() % 6) + 1);
    }
    auto lowestRoll = std::min_element(tempRolls.begin(), tempRolls.end());
    int sum = std::accumulate(tempRolls.begin(), tempRolls.end(), 0);
    sum -= *lowestRoll;
    statRolls.push_back(sum);
    sum = 0;
    tempRolls.erase(tempRolls.begin(), tempRolls.end());
  }
  std::sort(statRolls.begin(), statRolls.end(), std::greater<int>());
  for (int i = 0; i <= 5; i++) {
    int k = 1;
    int choice = 0;
    clearScreen();
    std::cout << "What would you like to assign to " << stats[i].returnName()
              << "? Pick by number, first number is 1, second is 2, etc"
              << std::endl;
    for (int currentStat : statRolls) {
      std::cout << k << ". " << currentStat << std::endl;
      k++;
    }
    std::cin >> choice;
    stats[i].setStat(statRolls[choice - 1]);
    statRolls.erase(statRolls.begin() + choice - 1);
  }
}
