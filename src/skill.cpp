#include "skill.hpp"
#include "Class.hpp"
#include <string>
#include <vector>

skill::skill(std::string Name, bool isProficient, int StatValue) {
  name = Name;
  proficient = isProficient;
  value = StatValue;
};

bool skill::returnProficient() { return proficient; }
int skill::returnValue() { return value; }
void skill::setModifier(int modifier) { value = modifier; }
void skill::setValue(int &proficiencyBonus) { value += proficiencyBonus; }

std::vector<skill> skills = {
    skill("Athletics", 0, 0),       skill("Acrobatics", 0, 0),
    skill("Sleight of Hand", 0, 0), skill("Stealth", 0, 0),
    skill("Arcana", 0, 0),          skill("History", 0, 0),
    skill("Investigation", 0, 0),   skill("Nature", 0, 0),
    skill("Religion", 0, 0),        skill("Animal Handling", 0, 0),
    skill("Insight", 0, 0),         skill("Medicine", 0, 0),
    skill("Perception", 0, 0),      skill("Survival", 0, 0),
    skill("Deception", 0, 0),       skill("Intimidation", 0, 0),
    skill("Performance", 0, 0),     skill("Persuasion", 0, 0),
};
void genSkills(int &classNumber, int &proficiencyBonus) {
  std::vector<int> indexes = classes[classNumber - 1].returnSkillIndexes();
}
