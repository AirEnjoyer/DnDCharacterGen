#include "saves.hpp"
#include "stat.hpp"
#include "Class.hpp"
#include <vector>
#include <string>

save::save(std::string SaveName, int statMod){
  saveStat = saveName;
  saveValue = statMod;
  proficient = false;
}


void save::setProficient(bool isProficient, int &proficiencyBonus){
    proficient = isProficient;
    if (proficient){
      saveValue += proficiencyBonus;
    }
}

std::vector<save> saves = {
  stat("Strength Save", stats[0].returnScore()),
  stat("Dexterity Save", stats[1].returnScore()),
  stat("Constitution Save", stats[2].returnScore()),
  stat("Wisdom Save", stats[3].returnScore()),
  stat("Intelligence Save", stats[4].returnScore()),
  stat("Charisma Save", stats[5].returnScore()),
}
