#include "writeToFile.hpp"
#include "Class.hpp"
#include "ClearScreen.hpp"
#include "getHome.hpp"
#include "saves.hpp"
#include "stat.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

void writeToFile(int &MaxHP, int &classNumber) {
  std::string homeDir;
  getHome(homeDir);
  std::string mkdir = "mkdir " + homeDir + "/Characters";
  std::system(homeDir.c_str());
  ClearScreen();
  std::string characterName;
  std::cout << "Enter your character's name: " << std::endl;
  std::cin >> characterName;
  ClearScreen();
  std::string path = homeDir + characterName + ".txt";
  std::ofstream file(path);
  file << "Name: " << characterName << std::endl << std::endl;
  file << "Class " << classes[classNumber - 1].returnName() << std::endl;
  file << std::endl;
  file << "HP: " << MaxHP << std::endl;
  file << std::endl;
  file << "Strength: " << std::endl;
  file << "Score: " << Strength.returnScore() << std::endl;
  file << "Modifier: " << Strength.returnModifier() << std::endl;
  file << "Saving Throw: " << StrengthSave.returnValue() << std::endl;
  file << std::endl;

  file << "Dexterity: " << std::endl;
  file << "Score: " << Dexterity.returnScore() << std::endl;
  file << "Modifier: " << Dexterity.returnModifier() << std::endl;
  file << "Saving Throw: " << DexteritySave.returnValue() << std::endl;
  file << std::endl;

  file << "Constitution: " << std::endl;
  file << "Score: " << Constitution.returnScore() << std::endl;
  file << "Modifier: " << Constitution.returnModifier() << std::endl;
  file << "Saving Throw: " << ConstitutionSave.returnValue() << std::endl;
  file << std::endl;

  file << "Wisdom: " << std::endl;
  file << "Score: " << Wisdom.returnScore() << std::endl;
  file << "Modifier: " << Wisdom.returnModifier() << std::endl;
  file << "Saving Throw: " << WisdomSave.returnValue() << std::endl;
  file << std::endl;

  file << "Intelligence: " << std::endl;
  file << "Score: " << Intelligence.returnScore() << std::endl;
  file << "Modifier: " << Intelligence.returnModifier() << std::endl;
  file << "Saving Throw: " << IntelligenceSave.returnValue() << std::endl;
  file << std::endl;

  file << "Charisma: " << std::endl;
  file << "Score: " << Charisma.returnScore() << std::endl;
  file << "Modifier: " << Charisma.returnModifier() << std::endl;
  file << "Saving Throw: " << CharismaSave.returnValue() << std::endl;
  file << std::endl;
  file.close();
  std::cout << "Written to " << path << std::endl;
}
