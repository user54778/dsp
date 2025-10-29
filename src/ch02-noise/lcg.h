#pragma once
#include <chrono>
#include <cstdint>
namespace noise {
/*
 * The Linear Congruential Generator (LCG) is used to
 * generate pseudo-random numbers.
 * This algorithm is based off a seed S, the new random number
 * R, and chosen constants a, b, and c.
 * R = (a * S + B) % c
 * Or the recurrence X_n+1 = (a * X_n + c) % m.
 * a is the multiplier
 * c is the increment
 * X is the seed.
 *
 * A continuous sequence of random numbers can be generated,
 * all starting from the same seed S/X.
 */
class LCG {
public:
  LCG(uint64_t seed);
  LCG();
  void reseed();
  double generate_uniform();

private:
  // https://en.wikipedia.org/wiki/Linear_congruential_generator
  // Choices for m vary with 3 common choices.
  // I chose the m a power of 2, c != 0.
  // Specifically, Borland C++.
  // Called Hull-Dobell Theorem.
  uint64_t seed_;
  const uint64_t a_ = 22695477;
  const uint64_t c_ = 1; //
  const uint64_t m_ = 1 << 31;
};
} // namespace noise
