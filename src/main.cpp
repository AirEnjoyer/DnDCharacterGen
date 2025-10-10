#include "Class.hpp"
#include "Clear.hpp"
#include "stat.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  srand(time(0));
  genStats();
  pickStats();
  pickClass();

  clearScreen();

  for (int i = 0; i <= 5; i++) {
    std::cout << stats[i].returnName() << ": " << stats[i].returnScore()
              << std::endl;
  }

  return 0;
}
