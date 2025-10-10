#include "getHome.hpp"

#include <cstdlib>
#include <string>

std::string homeDir = "~/Characters";

void getHome() {
#ifdef _WIN32
  homeDir = std::getenv("USERPROFILE");
#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__)
  homeDir = std::getenv("HOME");
#endif
}
