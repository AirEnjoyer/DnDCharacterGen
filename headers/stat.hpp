#ifndef STAT_HPP
#define STAT_HPP

#include <string>
#include <vector>

class stat {
private:
  std::string name;
  int score;
  int modifier;

public:
  stat(std::string Name);
  void setStat(int Score);
  std::string returnName();
  int returnScore();
  int returnModifier();
};

void pickStats();
extern std::vector<stat> stats;

#endif
