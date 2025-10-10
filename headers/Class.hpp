#ifndef CLASS_HPP
#define CLASS_HPP

#pragma once

#include <string>
#include <vector>

class Class {
private:
  std::string name;
  int hitDiceMaxRoll;
  std::vector<std::string> saves;
  std::vector<bool> savingThrows;

public:
  Class(std::string className, int hitDiceType, int save1, int save2);
  bool returnIsProficient(int index);
  int returnHitDice();
  std::string returnClassName();
};

void pickClass();

extern int classPicked;
extern std::vector<Class> classes;

#endif
