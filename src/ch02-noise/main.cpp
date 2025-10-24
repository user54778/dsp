#include "gaussian.h"
#include <iostream>
int main() {

  auto lcg = noise::LCG();
  /*
  auto gen = lcg.generate_uniform();

  for (int i = 0; i < 100; i++) {
    std::cout << lcg.generate_uniform() << std::endl;
  }

  std::cout << "\n\n";

  for (int i = 0; i < 100; i++) {
    std::cout << lcg.generate_uniform() << std::endl;
  }

  lcg.reseed();
  std::cout << "Reseed..." << "\n\n";

  for (int i = 0; i < 100; i++) {
    std::cout << lcg.generate_uniform() << std::endl;
  }
  */
  auto gaussian = noise::GaussianGenerator(lcg);
  auto x = gaussian.generate_gaussian();
  std::cout << x << std::endl;

  return 0;
}
