#include "writeToFile.hpp"
#include "Class.hpp"
#include "ClearScreen.hpp"
#include "getHome.hpp"
#include "saves.hpp"
#include "skill.hpp"
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
  file << "Class: " << classes[classNumber - 1].returnName() << std::endl;
  file << std::endl;
  file << "HP: " << MaxHP << std::endl;
  file << std::endl;
  file << "Strength: " << std::endl;
  file << "Score: " << Strength.returnScore() << std::endl;
  file << "Modifier: " << Strength.returnModifier() << std::endl;
  file << "Saving Throw: " << StrengthSave.returnValue() << std::endl;
  file << "Athletics: " << skills[0].returnValue() << std::endl;
  file << std::endl;

  file << "Dexterity: " << std::endl;
  file << "Score: " << Dexterity.returnScore() << std::endl;
  file << "Modifier: " << Dexterity.returnModifier() << std::endl;
  file << "Saving Throw: " << DexteritySave.returnValue() << std::endl;
  file << "Acrobatics: " << skills[1].returnValue() << std::endl;
  file << "Sleight of Hand: " << skills[2].returnValue() << std::endl;
  file << "Stealth: " << skills[3].returnValue() << std::endl;
  file << std::endl;

  file << "Constitution: " << std::endl;
  file << "Score: " << Constitution.returnScore() << std::endl;
  file << "Modifier: " << Constitution.returnModifier() << std::endl;
  file << "Saving Throw: " << ConstitutionSave.returnValue() << std::endl;
  file << std::endl;

  file << "Intelligence: " << std::endl;
  file << "Score: " << Intelligence.returnScore() << std::endl;
  file << "Modifier: " << Intelligence.returnModifier() << std::endl;
  file << "Saving Throw: " << IntelligenceSave.returnValue() << std::endl;
  file << "Arcana: " << skills[4].returnValue() << std::endl;
  file << "History: " << skills[5].returnValue() << std::endl;
  file << "Investigation: " << skills[6].returnValue() << std::endl;
  file << "Nature: " << skills[7].returnValue() << std::endl;
  file << "Religion: " << skills[8].returnValue() << std::endl;
  file << std::endl;

  file << "Wisdom: " << std::endl;
  file << "Score: " << Wisdom.returnScore() << std::endl;
  file << "Modifier: " << Wisdom.returnModifier() << std::endl;
  file << "Saving Throw: " << WisdomSave.returnValue() << std::endl;
  file << "Animal Handling: " << skills[9].returnValue() << std::endl;
  file << "Insight: " << skills[10].returnValue() << std::endl;
  file << "Medicine: " << skills[11].returnValue() << std::endl;
  file << "Perception: " << skills[12].returnValue() << std::endl;
  file << "Survival: " << skills[13].returnValue() << std::endl;
  file << std::endl;

  file << "Charisma: " << std::endl;
  file << "Score: " << Charisma.returnScore() << std::endl;
  file << "Modifier: " << Charisma.returnModifier() << std::endl;
  file << "Saving Throw: " << CharismaSave.returnValue() << std::endl;
  file << "Deception: " << skills[14].returnValue() << std::endl;
  file << "Intimidation: " << skills[15].returnValue() << std::endl;
  file << "Performance: " << skills[16].returnValue() << std::endl;
  file << "Persuasion: " << skills[17].returnValue() << std::endl;
  file << std::endl;
  file.close();
  std::cout << "Written to " << path << std::endl;
}
