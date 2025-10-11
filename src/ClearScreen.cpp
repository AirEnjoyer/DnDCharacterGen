#include "ClearScreen.hpp"
#include <cstdlib>

void ClearScreen() {
#ifdef _WIN32
  system("cls");
#elif __APPLE__
  system("clear");
#elif __linux__
  system("clear");
#endif
}
