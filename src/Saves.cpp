#include "Saves.hpp"
#include "Class.hpp"
#include "Level.hpp"
#include "stat.hpp"

#include <string>
#include <vector>

Save::Save(std::string saveName, bool Proficient, int stat) {
  saveStat = saveName;
  proficient = Proficient;
  saveValue = stat;
}

void Save::addProficiency() {
  if (proficient) {
    saveValue += ProficiencyBonus;
  }
}

int Save::returnValue() { return saveValue; }

std::vector<Save> saves = {
    Save("Strength Save", classes[classPicked].returnIsProficient(0),
         stats[0].returnModifier()),
    Save("Dexterity Save", classes[classPicked].returnIsProficient(1),
         stats[1].returnModifier()),
    Save("Constitution Save", classes[classPicked].returnIsProficient(2),
         stats[2].returnModifier()),
    Save("Wisdom Save", classes[classPicked].returnIsProficient(3),
         stats[3].returnModifier()),
    Save("Intelligence Save", classes[classPicked].returnIsProficient(4),
         stats[4].returnModifier()),
    Save("Charisma Save", classes[classPicked].returnIsProficient(5),
         stats[5].returnModifier()),
};

void addProficiencies() {
  if (classes[classPicked].returnIsProficient(0)) {
    saves[0].addProficiency();
  }
  if (classes[classPicked].returnIsProficient(1)) {
    saves[1].addProficiency();
  }
  if (classes[classPicked].returnIsProficient(2)) {
    saves[2].addProficiency();
  }
  if (classes[classPicked].returnIsProficient(3)) {
    saves[3].addProficiency();
  }
  if (classes[classPicked].returnIsProficient(4)) {
    saves[4].addProficiency();
  }
  if (classes[classPicked].returnIsProficient(4)) {
    saves[4].addProficiency();
  }
  if (classes[classPicked].returnIsProficient(5)) {
    saves[5].addProficiency();
  }
}
