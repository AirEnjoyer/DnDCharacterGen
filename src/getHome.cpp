#include "getHome.hpp"
#include <cstdlib>
#include <string>

void getHome(std::string &homeDir) {
#ifdef _WIN32
  homeDir = std::getenv("USERPROFILE");
  homeDir += "\\Characters\\"
#elif __APPLE__
  homeDir = std::getenv("HOME");
  homeDir += "/Characters/"
#elif __linux__
  homeDir = std::getenv("HOME");
  homeDir += "/Characters/";
#endif
}
