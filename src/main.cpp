#include <iostream>
#include <string>
#include <vector>
#include "stat.hpp"
#include <cstdlib>
#include <ctime>

int main(){
  srand(time(NULL));
  std::vector<int> rolls;
  genStats(rolls);
  Strength.pickStat(rolls);
  Dexterity.pickStat(rolls);
  Constitution.pickStat(rolls);
  Wisdom.pickStat(rolls);
  Intelligence.pickStat(rolls);
  Charisma.pickStat(rolls);
  return 0;
}
