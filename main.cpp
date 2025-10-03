#include <algorithm>
#include <map>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <utility>

void sleep(long int input) {
  std::this_thread::sleep_for(std::chrono::milliseconds(input));
}

void printStats(int stats[]) {
  for (int i = 0; i < 5; i++) {
    std::cout << stats[i] << " ";
    sleep(450);
  }
}

void getHitDice(int &hitDiceType, int &characterClass) {
  switch (characterClass) {
  case 1:
    hitDiceType = 12;
    break;
  case 3:
    hitDiceType = 10;
    break;
  case 6:
    hitDiceType = 10;
    break;
  case 8:
    hitDiceType = 10;
    break;
  case 9:
    hitDiceType = 10;
    break;
  case 12:
    hitDiceType = 6;
    break;
  case 13:
    hitDiceType = 6;
    break;
  default:
    hitDiceType = 8;
  }
}

void getMaxHP(int &maxHP, int &characterLevel, int &hitDiceType, int &conMod) {
  for (int i = 0; i < characterLevel - 1; ++i) {
    maxHP += (rand() % hitDiceType - 1) + 1;
  }
  maxHP += conMod * characterLevel;
}

void getStat(int &statSum, std::vector<int> &rolls,
             std::vector<int> &stats) {
  for (int j = 0; j < 6; j++) {
    statSum = 0;
    for (int i = 0; i < 4; i++) {
      sleep(200);
      rolls.push_back((rand() % 6) + 1);
      statSum += rolls[i];
    }
    auto lowestRoll = std::min_element(rolls.begin(), rolls.end());
    statSum -= *lowestRoll;
    rolls.clear();
    stats.push_back(statSum);
  }
}

int main() {
  srand(static_cast<unsigned int>(time(NULL)));
  system("clear");

  std::vector<int> stats;
  std::vector<int> rolls;
  int statSum, characterLevel, healthSum, characterClass, hitDiceType;
  std::vector<std::string> statNames = {"Strength",   "Dexterity",
                                        "Constitution", "Wisdom",
                                        "Intelligence", "Charisma"};

  std::vector<std::string> classes {"Barbarian", "Bard",    "Blood Hunter", "Cleric",
                          "Druid",     "Fighter", "Monk",         "Paladin",
                          "Ranger",    "Rogue",   "Sorcerer",     "Warlock",
                          "Wizard"};

  std::cout << "Enter Your Class" << std::endl;
  for (const std::string& currentClass : classes){
    std::cout << currentClass << std::endl;
  }
  std::cin >> characterClass;
  system("clear");



  getHitDice(hitDiceType, characterClass);
  std::cout << "Enter the character level" << std::endl << std::flush;
  std::cin >> characterLevel;
  system("clear");


  int choice;
  getStat(statSum, rolls, 
             stats);

  std::map<std::string, int> statsByName;
    std::sort(stats.begin(), stats.end(), std::greater<int>());
  for (std::string currentStatName : statNames){
    system("clear");
    std::cout << "What would you like to assign to " << currentStatName << "? Pick by number." << std::endl;
    for (int currentStat : stats){
      std::cout << currentStat<< std::endl << std::flush;
    }
      std::cin >> choice;
    statsByName.insert(std::make_pair(currentStatName, stats[choice - 1]));
    stats.erase(stats.begin() - (choice - 1));
  }


  std::cout << "Strength: " << statsByName["Strength"]<< std::endl;
  std::cout << "Dexterity: " << statsByName["Dexterity"]<< std::endl;
  std::cout << "Constitution: " << statsByName["Constitution"]<< std::endl;
  std::cout << "Wisdom: " << statsByName["Wisdom"]<< std::endl;
  std::cout << "Intelligence: " << statsByName["Intelligence"]<< std::endl;
  std::cout << "Charisma: " << statsByName["Charisma"]<< std::endl;

  std::cout << std::endl;

  int strMod = (statsByName["Strength"] - 10) / 2;
  int dexMod = (statsByName["Dexterity"] - 10) / 2;
  int conMod = (statsByName["Constitution"] - 10) / 2;
  int wisMod = (statsByName["Wisdom"] - 10) / 2;
  int intMod = (statsByName["Intelligence"] - 10) / 2;
  int chaMod = (statsByName["Charisma"] - 10) / 2;

  sleep(450);
  healthSum = hitDiceType;
  getMaxHP(healthSum, characterLevel, hitDiceType, conMod);
  std::cout << "Max HP: ";
  std::cout << healthSum << std::endl;

  return 0;
}
