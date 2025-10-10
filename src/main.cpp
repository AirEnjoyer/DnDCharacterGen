#include <iostream>
#include <string>
#include <vector>
#include "HP.hpp"
#include "stat.hpp"
#include "Class.hpp"
#include "ClearScreen.hpp"
#include "Level.hpp"
#include "saves.hpp"
#include <cstdlib>
#include <ctime>

int main(){
  srand(time(NULL));
  ClearScreen();
  std::cout << "Pick your class by number: " << std::endl;
  for (Class currentClass : classes){
    std::cout << currentClass.returnName() << std::endl;
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

  StrengthSave.setProficient(strengthProficient, proficiencyBonus);
  DexteritySave.setProficient(dexterityProficient, proficiencyBonus);
  ConstitutionSave.setProficient(constitutionProficient, proficiencyBonus);
  WisdomSave.setProficient(wisdomProficient, proficiencyBonus);
  IntelligenceSave.setProficient(intelligenceProficient, proficiencyBonus);
  CharismaSave.setProficient(charismaProficient, proficiencyBonus);

  std::cout <<  Strength.returnModifier() << std::endl;
  std::cout << proficiencyBonus << std::endl;
  std::cout << StrengthSave.returnIsProficient() << std::endl;
  std::cout << StrengthSave.returnValue() << std::endl;

  return 0;
}
