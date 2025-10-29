#include "clt.h"
namespace noise {
CLTGenerator::CLTGenerator(LCG &rng, int samples = 12)
    : rng_{rng}, samples_{samples} {}

double CLTGenerator::generate() {
  double sum = 0.0;
  for (int i = 0; i < samples_; i++) {
    sum += rng_.generate_uniform();
  }
  return sum;
}

int CLTGenerator::getSampleCount() const { return samples_; }
void CLTGenerator::setSampleCount(int samples) { samples_ = samples; }
} // namespace noise
