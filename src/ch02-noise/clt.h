#include "lcg.h"
namespace noise {
// Generate distributions that showcase the effects of the Central Limit
// Theorem. It ustilizes n samples_ and a RNG from the LCG.
class CLTGenerator {
public:
  CLTGenerator(LCG &rng, int samples);
  double generate();

  void setSampleCount(int samples);
  int getSampleCount() const;

private:
  LCG &rng_;
  int samples_;
};
} // namespace noise
