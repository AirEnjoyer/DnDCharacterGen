#include "Class.hpp"
#include "ClearScreen.hpp"
#include "HP.hpp"
#include "Level.hpp"
#include "saves.hpp"
#include "skill.hpp"
#include "stat.hpp"
#include "writeToFile.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
  srand(time(NULL));
  ClearScreen();
  std::cout << "Pick your class by number: " << std::endl;
  int num = 1;
  for (Class currentClass : classes) {
    std::cout << num << ": " << currentClass.returnName() << std::endl;
    num++;
  }
  int classNumber;
  std::cin >> classNumber;
  std::vector<int> rolls;
  ClearScreen();
  std::cout << "Do you want to roll for stats or use custom stats? (Y or N)"
            << std::endl;
  char choice;
  std::cin >> choice;

  if (choice == 'Y' || choice == 'y') {
    ClearScreen();
    std::cout << "Enter the strength score (3 - 18)" << std::endl;
    int input;
    std::cin >> input;
    Strength.inputScore(input);
    ClearScreen();
    std::cout << "Enter the dexterity score (3 - 18)" << std::endl;
    std::cin >> input;
    Dexterity.inputScore(input);
    ClearScreen();
    std::cout << "Enter the constitution score (3 - 18)" << std::endl;
    std::cin >> input;
    Constitution.inputScore(input);
    ClearScreen();
    std::cout << "Enter the intelligence score (3 - 18)" << std::endl;
    std::cin >> input;
    Intelligence.inputScore(input);
    ClearScreen();
    std::cout << "Enter the wisdom score (3 - 18)" << std::endl;
    std::cin >> input;
    ClearScreen();
    Wisdom.inputScore(input);
    std::cout << "Enter the charisma score (3 - 18)" << std::endl;
    std::cin >> input;
    Charisma.inputScore(input);
    ClearScreen();
  } else {
    ClearScreen();
    genStats(rolls);
    Strength.pickStat(rolls);
    Dexterity.pickStat(rolls);
    Constitution.pickStat(rolls);
    Intelligence.pickStat(rolls);
    Wisdom.pickStat(rolls);
    Charisma.pickStat(rolls);
    ClearScreen();
  }

  int characterLevel, proficiencyBonus, MaxHP;
  getLevel(characterLevel);
  ClearScreen();
  getProficiency(characterLevel, proficiencyBonus);

  genSkills(classNumber, proficiencyBonus);

  skills[0].setModifier(Strength.returnModifier());
  for (int i = 1; i < 4; i++) {
    skills[i].setModifier(Dexterity.returnModifier());
  }
  for (int i = 4; i < 9; i++) {
    skills[i].setModifier(Intelligence.returnModifier());
  }
  for (int i = 9; i < 13; i++) {
    skills[i].setModifier(Wisdom.returnModifier());
  }
  for (int i = 13; i < 18; i++) {
    skills[i].setModifier(Charisma.returnModifier());
  }

  std::vector<int> indexes;
  switch (classNumber) {
  case 1:
    indexes = {9, 0, 15, 7, 12, 13};
    break;
  case 2:
    for (int i = 0; i < 18; i++)
      indexes.push_back(i);
    break;
  case 3:
    indexes = {5, 10, 17, 8};
    break;
  case 4:
    indexes = {4, 9, 10, 11, 7, 12, 8, 13};
    break;
  case 5:
    indexes = {1, 9, 0, 5, 7, 10, 15, 17, 12, 13};
    break;
  case 6:
    indexes = {1, 0, 5, 10, 8, 3};
    break;
  case 7:
    indexes = {0, 10, 15, 11, 17, 8};
    break;
  case 8:
    indexes = {9, 0, 10, 6, 7, 12, 3, 13};
    break;
  case 9:
    indexes = {1, 0, 14, 10, 15, 6, 12, 17, 2, 3};
    break;
  case 10:
    indexes = {4, 14, 10, 15, 17, 8};
    break;
  case 11:
    indexes = {4, 14, 5, 15, 6, 7, 8};
    break;
  case 12:
    indexes = {4, 5, 10, 6, 11, 7, 8};
    break;
  }

  classes[classNumber - 1].pickSkills(proficiencyBonus, indexes);

  int hitDice = classes[classNumber - 1].returnHitDice();
  getHP(MaxHP, characterLevel, hitDice);

  bool strengthProficient = classes[classNumber - 1].returnSave(0);
  bool dexterityProficient = classes[classNumber - 1].returnSave(1);
  bool constitutionProficient = classes[classNumber - 1].returnSave(2);
  bool wisdomProficient = classes[classNumber - 1].returnSave(3);
  bool intelligenceProficient = classes[classNumber - 1].returnSave(4);
  bool charismaProficient = classes[classNumber - 1].returnSave(5);

  StrengthSave.setValue((Strength.returnModifier()) +
                        (proficiencyBonus * strengthProficient));

  DexteritySave.setValue((Dexterity.returnModifier()) +
                         (proficiencyBonus * dexterityProficient));

  ConstitutionSave.setValue((Constitution.returnModifier()) +
                            (proficiencyBonus * constitutionProficient));

  WisdomSave.setValue((Wisdom.returnModifier()) +
                      (proficiencyBonus * wisdomProficient));

  IntelligenceSave.setValue((Intelligence.returnModifier()) +
                            (proficiencyBonus * intelligenceProficient));

  CharismaSave.setValue((Charisma.returnModifier()) +
                        (proficiencyBonus * charismaProficient));

  writeToFile(MaxHP, classNumber);
}
