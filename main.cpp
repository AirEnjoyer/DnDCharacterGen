#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

void sleep(long int input) {
  std::this_thread::sleep_for(std::chrono::milliseconds(input));
}

void printStats(int stats[]) {
  for (int i = 0; i < 5; i++) {
    std::cout << stats[i] << " ";
    sleep(450);
  }
}

void getHitDice(int *hitDiceType, int *characterClass) {
  switch (*characterClass) {
  case 1:
    *hitDiceType = 12;
    break;
  case 3:
    *hitDiceType = 10;
    break;
  case 6:
    *hitDiceType = 10;
    break;
  case 8:
    *hitDiceType = 10;
    break;
  case 9:
    *hitDiceType = 10;
    break;
  case 12:
    *hitDiceType = 6;
    break;
  case 13:
    *hitDiceType = 6;
    break;
  default:
    *hitDiceType = 8;
  }
}

void getMaxHP(int *maxHP, int *characterLevel, int *hitDiceType) {
  srand((unsigned int)time(NULL));
  for (int i = 0; i < *characterLevel - 1; ++i) {
    *maxHP += (rand() % *hitDiceType - 1) + 1;
  }
}

void getStat(int *statSum, int *rolls, int amountOfRolls) {
  srand((unsigned int)time(NULL));
  for (int j = 0; j < 6; j++) {
    *statSum = 0;
    for (int i = 0; i < amountOfRolls; i++) {
      rolls[i] = (rand() % 6) + 1;
      *statSum += rolls[i];
    }
    int *lowestRoll = std::min_element(rolls, rolls + 4);
    *statSum -= *lowestRoll;
  }
}

int main() {

  system("clear");

  const int amountOfRolls = 4;
  int rolls[amountOfRolls];
  int statSum, characterLevel, healthSum, characterClass, hitDiceType;
  std::string classes[13]{"Barbarian", "Bard",    "Blood Hunter", "Cleric",
                          "Druid",     "Fighter", "Monk",         "Paladin",
                          "Ranger",    "Rogue",   "Sorcerer",     "Warlock",
                          "Wizard"};

  std::cout << "Enter Your Class" << std::endl;
  for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
    std::cout << i + 1 << ". " << classes[i] << std::endl;
  }
  std::cin >> characterClass;

  getHitDice(&hitDiceType, &characterClass);
  system("clear");

  std::cout << "Enter the character level" << std::endl;
  std::cin >> characterLevel;
  std::cout << std::endl;

  system("clear");
  std::vector<int> stats;
  std::cout << "Generating stats, wait about 10 seconds" << std::endl;
  for (int i = 0; i < 6; i++) {
    sleep(2000);
    getStat(&statSum, rolls, amountOfRolls);
    stats.push_back(statSum);
  }
  std::cout << "Stats generated!" << std::endl;
  sleep(1000);

  system("clear");
  std::cout << "Stats: " << std::endl;
  std::sort(stats.begin(), stats.end(), std::greater<int>());
  for (int vals : stats) {
    std::cout << vals << " " << std::flush;
    sleep(450);
  }

  std::cout << std::endl;

  sleep(450);
  healthSum = hitDiceType;
  getMaxHP(&healthSum, &characterLevel, &hitDiceType);
  std::cout << "Max HP: ";
  std::cout << healthSum << std::endl;

  return 0;
}
