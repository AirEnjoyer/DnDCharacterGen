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

void clearScreen(){

#ifdef _WIN32
    system("cls");
#else 
    system("clear");
  #endif 
  
}

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

void getMaxHP(int &healthSum, int &characterLevel, int &hitDiceType, int &conMod) {
  std::cout << "Do you want to simulate rolling for health? If you don't, the average will be used. Y for yes N for no" << std::endl << std::flush;
  char rollForHp;
  bool roll;
  std::cin >> rollForHp;
  if (rollForHp == 'Y' || rollForHp == 'y'){
    roll = true;
  } else {
    roll = false;
  }

  
  if (roll){
  for (int i = 0; i < characterLevel - 1; ++i) {
    healthSum += (rand() % hitDiceType - 1) + 1;
  }
  } else {
    healthSum += ((hitDiceType / 2 ) + 1) * characterLevel;
  }
  healthSum += conMod * characterLevel;
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
  clearScreen();

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
    int e = 1;
  for (const std::string& currentClass : classes){
    std::cout << e << ": " << currentClass << std::endl;
    e++;
  }
  std::cin >> characterClass;
  clearScreen();



  getHitDice(hitDiceType, characterClass);
  std::cout << "Enter the character level" << std::endl << std::flush;
  std::cin >> characterLevel;
  clearScreen();


  int choice;
  std::cout << "Generating Stats" << std::endl;
  getStat(statSum, rolls, 
             stats);
  std::cout << "Stats Generated!" << std::endl << std::flush;
  sleep(500);
  clearScreen();

  std::map<std::string, int> statsByName;
    std::sort(stats.begin(), stats.end(), std::greater<int>());
  for (std::string currentStatName : statNames){
    clearScreen();
    std::cout << "What would you like to assign to " << currentStatName << "? Pick by number." << std::endl;
    for (int currentStat : stats){
      std::cout << currentStat<< std::endl << std::flush;
    }
      std::cin >> choice;
    statsByName.insert(std::make_pair(currentStatName, stats[choice - 1]));
    stats.erase(stats.begin() - (choice - 1));
  }



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
  clearScreen();
  std::cout << "Strength: " << statsByName["Strength"]<< std::endl;
  std::cout << "Dexterity: " << statsByName["Dexterity"]<< std::endl;
  std::cout << "Constitution: " << statsByName["Constitution"]<< std::endl;
  std::cout << "Wisdom: " << statsByName["Wisdom"]<< std::endl;
  std::cout << "Intelligence: " << statsByName["Intelligence"]<< std::endl;
  std::cout << "Charisma: " << statsByName["Charisma"]<< std::endl;
  std::cout << "Max HP: ";
  std::cout << healthSum << std::endl;

  return 0;
}
