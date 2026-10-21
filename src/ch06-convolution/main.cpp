#include <iostream>
#include <random>

namespace convolve {

// A simple wrapper data type for creating a uniformly real distributed number.
struct DistData {
  float a_;
  float b_;
  std::mt19937 gen_;
  std::uniform_real_distribution<> dis_;

  DistData(float a, float b)
      : a_{a}, b_{b}, gen_{std::random_device{}()}, dis_{a_, b_} {}
};

std::vector<float> buildRandomVector(int n, DistData &d) {
  std::vector<float> v;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    v[i] = d.dis_(d.gen_);
  }
  return v;
}

std::vector<float> convolution(std::vector<float> &inputSignal,
                               std::vector<float> &impulseResponse) {
  std::vector<float> outputSignal;
  outputSignal.resize((inputSignal.size() + impulseResponse.size()) - 1, 0);

  int n = outputSignal.size();
  int m = impulseResponse.size();
  int k = inputSignal.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // invert logic to avoid `break`
      if (i - j >= 0 && i - j < k) {
        // sum the products of the impulseResponse (kernel) and correct
        // position in inputSignal
        outputSignal[i] += impulseResponse[j] * inputSignal[i - j];
      }
    }
  }

  return outputSignal;
}

}; // namespace convolve

int main() {

  int n{}; // length of input signal
  int m{}; // length of impulse response
  auto readLengths = [&n, &m]() {
    for (auto target : {&n, &m}) {
      while (!(std::cin >> *target)) {
        // clears buffer
        std::cin.clear();
        // ignore characters until newline is encountered
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid integer; enter a new one: ";
      }
    }
  };

  std::cout << "Enter length of input signal and length of impulse response: ";
  readLengths();
  std::cout << n << ' ' << m << '\n';

  convolve::DistData d{-3.0, 3.0};
  auto inputSignal = convolve::buildRandomVector(n, d);
  auto impulseResponse = convolve::buildRandomVector(m, d);

  std::cout << "Input data: ";
  for (const auto &v : inputSignal) {
    std::cout << v << ' ';
  }
  std::cout << '\n';

  std::cout << "Impulse Response: ";
  for (const auto &v : impulseResponse) {
    std::cout << v << ' ';
  }
  std::cout << '\n';

  // NOTE: Output amplitude can be larger than the input and impulse range,
  // due to large impulse responses leading to larger outputs as we're summing
  // more products together.
  auto outputSignal = convolve::convolution(inputSignal, impulseResponse);
  std::cout << "Output Signal: ";
  for (const auto &v : outputSignal) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}
