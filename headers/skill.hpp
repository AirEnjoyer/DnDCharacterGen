#ifndef SKILL_HPP
#define SKILL_HPP

#include <string>
#include <vector>

class skill {
private:
  std::string name;
  bool proficient;
  int value;

public:
  skill(std::string Name, bool isProficient, int StatValue);
  bool returnProficient();
  int returnValue();
  void setValue(int &proficiencyBonus);
  void setModifier(int modifier);
};

extern std::vector<skill> skills;

void genSkills(int &classNumber, int &proficiencyBonus);

#endif
