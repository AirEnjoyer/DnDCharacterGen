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
  void pickStat(std::vector<int> &rolls);
  std::string returnName();
  int returnScore();
  int returnModifier();
  void inputScore(int input);
};
void genStats(std::vector<int> &rolls);
extern stat Strength, Dexterity, Constitution, Wisdom, Intelligence, Charisma;

#endif
