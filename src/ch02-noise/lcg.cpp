#include "lcg.h"
#include <chrono>
#include <ctime>

namespace noise {
// LCG creates a Linear Congruential Generator with a given
// seed `seed`.
LCG::LCG(uint64_t seed) : seed_{seed} {}

LCG::LCG() {
  seed_ = static_cast<uint64_t>(
      std::chrono::system_clock::now().time_since_epoch().count());
}

/**
 * reseed() provides the option of reseeding the RNG
 * if the user wants the number sequence to change.
 */
void LCG::reseed() {
  seed_ = std::chrono::system_clock::now().time_since_epoch().count();
}

/**
 * generate() uniform random numbers between 0 and 1
 * following the LCG algorithm.
 * R = (a * S + b) % c.
 */
double LCG::generate_uniform() {
  seed_ = (a_ * seed_ + c_) % m_;

  // normalize to [0, 1)
  return seed_ / static_cast<double>(m_);
}
} // namespace noise
