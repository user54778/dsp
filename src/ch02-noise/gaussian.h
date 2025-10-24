#pragma once
#include "lcg.h"
/*
 * A Class for the Box-Muller Transform, which generates
 * normally distributed random numbers.
 * It takes random numbers R1 and R2 generated from a linear congruential
 * generator, resulting in X being normally distributed with a mean
 * of zero, and standard deviation of one.
 * The log is base e, and cosine in radians.
 *
 * X = (-2logR_1)^1/2 * cos(2piR_2)
 */
namespace noise {
class GaussianGenerator {
public:
  GaussianGenerator(LCG &rng);

  double generate_gaussian();

private:
  LCG &rng_;
};
} // namespace noise
