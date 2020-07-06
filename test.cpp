#include <iostream>

int main(int argc, char const *argv[]) {
#ifdef __linux__
  std::cerr << "Unix test fail" << std::endl;
  return 1;
#elif WIN32
  std::cout << "Win test ok" << std::endl;
  return 0;
#endif
}
