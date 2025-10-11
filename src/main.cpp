#include "Class.hpp"
#include "ClearScreen.hpp"
#include "HP.hpp"
#include "Level.hpp"
#include "saves.hpp"
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
  genStats(rolls);
  Strength.pickStat(rolls);
  Dexterity.pickStat(rolls);
  Constitution.pickStat(rolls);
  Wisdom.pickStat(rolls);
  Intelligence.pickStat(rolls);
  Charisma.pickStat(rolls);
  ClearScreen();

  int characterLevel, proficiencyBonus, MaxHP;
  getLevel(characterLevel);
  ClearScreen();
  getProficiency(characterLevel, proficiencyBonus);

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

  std::cout << MaxHP << std::endl;

  writeToFile(MaxHP, classNumber);

  return 0;
}
