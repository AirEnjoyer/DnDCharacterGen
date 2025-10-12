#include "Class.hpp"
#include "ClearScreen.hpp"
#include "skill.hpp"
#include <iostream>
#include <string>
#include <vector>

Class::Class(std::string name, int hitDiceType, int save1, int save2,
             std::vector<std::string> skillOptions, int skillAmount) {
  className = name;
  for (int i = 0; i <= 6; i++) {
    saves.push_back(false);
  }
  saves[save1] = true;
  saves[save2] = true;
  hitDiceMaxRoll = hitDiceType;
  skillNames = skillOptions;
  amountOfSkills = skillAmount;
};

int Class::returnAmountOfSkills() { return amountOfSkills; }

void Class::pickSkills(int &proficiencyBonus, std::vector<int> indexes) {
  std::cout << "Pick your skills by number" << std::endl;
  int k = 1;
  for (std::string currentSkill : skillNames) {
    std::cout << k << ": " << currentSkill << std::endl;
    k++;
  }
  for (int i = amountOfSkills; i > 0; i--) {
    int index;
    std::cin >> index;
    index--;
    skillIndexes.push_back(indexes[index]);
    skills[indexes[index]].setValue(proficiencyBonus);
  }
  std::cin.get();
  ClearScreen();
}

std::string Class::returnName() { return className; }

int Class::returnHitDice() { return hitDiceMaxRoll; }

bool Class::returnSave(int index) { return saves[index]; }

std::vector<int> Class::returnSkillIndexes() { return skillIndexes; }

std::vector<std::string> returnBarbarianSkills() {
  return {"Animal Handling", "Athletics",  "Intimidation",
          "Nature",          "Perception", "Survival"};
};

std::vector<std::string> returnBardSkills() {
  return {"Athletics",   "Acrobatics",      "Sleight of Hand", "Stealth",
          "Arcana",      "History",         "Investigation",   "Nature",
          "Religion",    "Animal Handling", "Insight",         "Medicine",
          "Perception",  "Survival",        "Deception",       "Intimidation",
          "Performance", "Persuasion"};
};

std::vector<std::string> returnClericSkills() {
  return {"History", "Insight", "Persuasion", "Religion"};
}

std::vector<std::string> returnDruidSkills() {
  return {
      "Arcana", "Animal Handling", "Insight",  "Medicine",
      "Nature", "Perception",      "Religion", "Survival",
  };
}

std::vector<std::string> returnFighterSkills() {
  return {
      "Acrobatics",   "Animal Handling", "Athletics",  "History",  "Insight",
      "Intimidation", "Persuasion",      "Perception", "Survival",
  };
}

std::vector<std::string> returnMonkSkills() {
  return {
      "Acrobatics", "Athletics", "History", "Insight", "Religion", "Stealth",
  };
}

std::vector<std::string> returnPaladinSkills() {
  return {
      "Athletics", "Insight",    "Intimidation",
      "Medicine",  "Persuasion", "Religion",
  };
}

std::vector<std::string> returnRangerSkills() {
  return {
      "Animal Handling", "Athletics",  "Insight", "Investigation",
      "Nature",          "Perception", "Stealth", "Survival",
  };
}

std::vector<std::string> returnRogueSkills() {
  return {"Acrobatics",      "Athletics",     "Deception",  "Insight",
          "Intimidation",    "Investigation", "Perception", "Persuasion",
          "Sleight of Hand", "Stealth"};
}

std::vector<std::string> returnSorcererSkills() {
  return {"Arcana",       "Deception",  "Insight",
          "Intimidation", "Persuasion", "Religion"};
}

std::vector<std::string> returnWarlockSkills() {
  return {
      "Arcana",        "Deception", "History",  "Intimidation",
      "Investigation", "Nature",    "Religion",
  };
}

std::vector<std::string> returnWizardSkills() {
  return {
      "Arcana",   "History", "Insight",  "Investigation",
      "Medicine", "Nature",  "Religion",
  };
}

std::vector<Class> classes = {
    Class("Barbarian", 12, 0, 2, returnBarbarianSkills(), 2),
    Class("Bard", 8, 1, 5, returnBardSkills(), 3),
    Class("Cleric", 8, 3, 5, returnClericSkills(), 2),
    Class("Druid", 8, 4, 5, returnDruidSkills(), 2),
    Class("Fighter", 10, 0, 2, returnFighterSkills(), 2),
    Class("Monk", 8, 0, 1, returnMonkSkills(), 2),
    Class("Paladin", 10, 3, 5, returnPaladinSkills(), 2),
    Class("Ranger", 10, 0, 1, returnRangerSkills(), 3),
    Class("Rogue", 8, 1, 4, returnRogueSkills(), 4),
    Class("Sorcerer", 6, 2, 5, returnSorcererSkills(), 2),
    Class("Warlock", 8, 3, 5, returnWarlockSkills(), 2),
    Class("Wizard", 8, 3, 4, returnWizardSkills(), 2),
};
