#include "pch.h"
#include <iostream>
#include <vector>
#include "LazyFiboNumbersGenerator.h"
#include "LazyPythagoreanTriplesGenerator.h"

int main() {
	auto fibNumbers = FiboSeqGenerator::getFiboGenerator(1);
	auto pythTriplesGenerator = PythagoreanTriplesGenerator::getPythagoreanTriplesGenerator(1);

	unsigned long long f = 0;
	while(f < std::numeric_limits<size_t>::max()) {
		const auto old = f;
		f = fibNumbers();
		if (old > f) break;
		std::cout << f << '\n';
	}

	std::cout << "\n\n";

	FiboGen fibGen;
	for (auto i = 0; i < 15; ++i)
		std::cout << fibGen() << '\n';
	getchar();
	while (true) 
		std::cout << pythTriplesGenerator() << "\n";;

}

