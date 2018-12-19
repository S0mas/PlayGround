#include "pch.h"
#include <iostream>
#include <vector>
#include "LazyFiboNumbersGenerator.h"
#include "LazyPythagoreanTriplesGenerator.h"
/*generator<int> generatorForNumbers(int begin, int inc = 1) {

	for (int i = begin;; i += inc) {
		co_yield i;
	}

}*/

void f() {
  while (true) {
    for (auto z = 2;; ++z) {
      auto i = 0;
      for (auto x = 1; x < z; ++x) {
        double root = 0;
        if (isSqrtRootInteger(pow(z, 2) - pow(x, 2), root)) {
          ++i;
          std::cout << "X: " << x << " Y: " << root << " Z: " << z << '\n';
          if (i > 1) getchar();
        }
      }
    }
  }
}

int main() {
	auto fibNumbersPass10 = FiboSeqGenerator::getFiboGenerator(11);
	auto fibNumbers = FiboSeqGenerator::getFiboGenerator(1);
	auto pythTriplesGenerator = PythagoreanTriplesGenerator::getPythagoreanTriplesGenerator(1);
	for (auto i = 0; i < 10; ++i) 
		std::cout << fibNumbersPass10() << " ";

	std::cout << "\n\n";

	for (auto i = 0; i < 20; ++i) 
		std::cout << fibNumbers() << " ";

	std::cout << "\n\n";

	for (auto i = 0; i < 10; ++i)
		std::cout << pythTriplesGenerator() << "\n";
	getchar();
	return 0;

}

