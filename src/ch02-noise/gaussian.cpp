#include "gaussian.h"
#include <cmath>
namespace noise {

// LCG::LCG(uint64_t seed) : seed_{seed} {}
GaussianGenerator::GaussianGenerator(LCG &rng) : rng_{rng} {}

// Generate a normally distributed number X from random numbers
// R1 and R2, based on the LCG given in the constructor.
double GaussianGenerator::generate_gaussian() {
  //  X = (-2logR_1)^1/2 * cos(2piR_2)
  /*
  auto r1 = (-2 * std::log(rng_.generate_uniform()));
  r1 = std::exp(0.5 * r1);
  auto r2 = std::cos(2 * (M_PI * (rng_.generate_uniform())));
  return r1 * r2;
  */
  double u1 = rng_.generate_uniform();
  double u2 = rng_.generate_uniform();

  // sqrt(-2 * log(u1))
  double r = std::sqrt(-2.0 * std::log(u1));

  // cos(2π * u2)
  double theta = std::cos(2.0 * M_PI * u2);

  return r * theta;
}
} // namespace noise
