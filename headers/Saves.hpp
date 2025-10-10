#ifndef SAVES_HPP
#define SAVES_HPP

#include <string>
#include <vector>

class Save {
private:
  std::string saveStat;
  bool proficient;
  int saveValue;

public:
  Save(std::string saveName, bool Proficient, int stat);
  void addProficiency();
  int returnValue();
};

extern std::vector<Save> saves;

#endif
