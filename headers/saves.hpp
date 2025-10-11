#ifndef SAVES_HPP
#define SAVES_HPP

#include <string>
class save {
private:
  std::string saveStat;
  int saveValue;
  bool proficient;

public:
  save(std::string SaveName, int statMod);
  void setValue(int value);
  int returnValue();
  bool returnIsProficient();
};

extern save StrengthSave, DexteritySave, ConstitutionSave, WisdomSave,
    IntelligenceSave, CharismaSave;

#endif
