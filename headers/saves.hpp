#ifndef SAVES_HPP
#define SAVES_HPP

#include <string>
#include <vector>
class save{
private:
std::string saveStat;
  int saveValue;
  bool proficient;
public:
save(std::string SaveName, int statMod);
  void setProficient(bool isProficient, int &proficiencyBonus);
  int returnValue();
  bool returnIsProficient();
};

extern save StrengthSave, DexteritySave, ConstitutionSave, WisdomSave, IntelligenceSave, CharismaSave;

#endif
