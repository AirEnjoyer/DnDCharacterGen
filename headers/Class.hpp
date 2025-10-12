#ifndef CLASS_HPP
#define CLASS_HPP

#include <string>
#include <vector>
class Class {
private:
  std::string className;
  int hitDiceMaxRoll;
  std::vector<std::string> skillNames;
  std::vector<bool> saves;
  int amountOfSkills;
  std::vector<int> skillIndexes;

public:
  Class(std::string name, int hitDiceType, int save1, int save2,
        std::vector<std::string> skillOptions, int skillAmount);
  std::string returnName();
  int returnHitDice();
  bool returnSave(int index);
  void pickSkills(int &proficiencyBonus, std::vector<int> indexes);
  std::vector<int> returnSkillIndexes();
  int returnAmountOfSkills();
};

extern std::vector<Class> classes;

#endif
