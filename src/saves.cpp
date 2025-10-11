#include "saves.hpp"
#include "stat.hpp"
#include <string>

save::save(std::string SaveName, int statMod) {
  saveStat = SaveName;
  saveValue = statMod;
  proficient = false;
};

void save::setValue(int value) { saveValue = value; };

bool save::returnIsProficient() { return proficient; };

int save::returnValue() { return saveValue; };

save StrengthSave("Strength Save", Strength.returnModifier());
save DexteritySave("Dexterity Save", Dexterity.returnModifier());
save ConstitutionSave("Constitution Save", Constitution.returnModifier());
save WisdomSave("Wisdom Save", Wisdom.returnModifier());
save IntelligenceSave("Intelligence Save", Intelligence.returnModifier());
save CharismaSave("Charisma Save", Charisma.returnModifier());
