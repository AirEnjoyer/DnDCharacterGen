#include "Class.hpp"
#include "Clear.hpp"
#include "stat.hpp"
#include <iostream>

int main() {
  pickClass();
  pickStats();

  clearScreen();

  for (int i = 0; i <= 5; i++) {
    std::cout << stats[i].returnName() << ": " << stats[i].returnScore()
              << std::endl;
  }

  return 0;
}
