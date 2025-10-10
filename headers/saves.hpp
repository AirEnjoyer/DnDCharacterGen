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
save(std::string saveName, int statMod);
  void setProficient(bool isProficient, int &proficiencyBonus);
};

extern std::vector<save> saves;

#endif
