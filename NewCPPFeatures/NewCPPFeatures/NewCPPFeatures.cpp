#include "pch.h"
#include <iostream>
#include <vector>
#include "LazyFiboNumbersGenerator.h"

/*generator<int> generatorForNumbers(int begin, int inc = 1) {

	for (int i = begin;; i += inc) {
		co_yield i;
	}

}*/

int main() {
	auto fibNumbersPass10 = FiboSeqGenerator::getFiboGenerator(11);
	auto fibNumbers = FiboSeqGenerator::getFiboGenerator(1);

	for (auto i = 0; i < 10; ++i) 
		std::cout << fibNumbersPass10() << " ";

	std::cout << "\n\n";

	for (auto i = 0; i < 20; ++i) 
		std::cout << fibNumbers() << " ";
	getchar();
	return 0;

}

