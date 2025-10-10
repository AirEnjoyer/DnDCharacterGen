#include "Clear.hpp"
#include <cstdlib>

void clearScreen() {
#ifdef _WIN32
  system("cls");
#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__)
  system("clear");
#endif
}
