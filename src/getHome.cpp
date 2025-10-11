#include "getHome.hpp"
#include <cstdlib>
#include <string>

void getHome(std::string &homeDir) {
#ifdef _WIN32
  homeDir = std::getenv("USERPROFILE");
#elif __APPLE__
  homeDir = std::getenv("HOME");
#elif __linux__
  homeDir = std::getenv("HOME");
#endif
}
