#ifndef CLASS_HPP 
#define CLASS_HPP 

#include <string>
#include <vector>
class Class{
private:
  std::string className;
 int hitDiceMaxRoll;
std::vector<bool> saves;
  public:
  Class(std::string name, int hitDiceType, int save1, int save2 );
std::string returnName();
  int returnHitDice();
  bool returnSave(int index);
};

  extern std::vector<Class> classes;

#endif
