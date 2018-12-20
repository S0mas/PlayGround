#include "pch.h"
#include <cmath>
#include <sstream>
#include <iostream>

static bool isSqrtRootInteger(const int number, double& root)
{
	if (number == 0) return false;
	root = std::sqrt(number);
	return root == static_cast<int>(root);
}

class PythagoreanTriplesGenerator {
	static auto getPythagoreanTriplesGenerator_(const int x, const int z) {
		return [x = x, z = z]() mutable {
			goto resume;
			while (true) {
				for (; ; ++z) {
					for (x = 1; x < z; ++x) {
					resume:
						double root = 0;
						if (isSqrtRootInteger(pow(z, 2) - pow(x, 2), root))
							return PythagoreanTriple(x++, root, z);
					}
				}
			}
		};
	}
public:
	static auto getPythagoreanTriplesGenerator(const int startId = 1) {
		auto i = 0;
		while (true) {
			for (auto z = 2; ; ++z) {
				for (auto x = 1; x < z; ++x) {
					double root = 0;
					if (isSqrtRootInteger(pow(z, 2) - pow(x, 2), root))
						++i;
					if (i >= startId)
						return getPythagoreanTriplesGenerator_(x, z);
				}
			}
		}
	}

	struct PythagoreanTriple {
		PythagoreanTriple(const int x, const int y, const int z) : x_(x), y_(y), z_(z) {}
		const int x_;
		const int y_;
		const int z_;
	};
};

inline std::ostream& operator<<(std::ostream &output, const PythagoreanTriplesGenerator::PythagoreanTriple &p) {
	output << "X: " << p.x_ << " Y: " << p.y_ << " Z: " << p.z_ << '\n';
	return output;
}

int main() {
	auto pythTriplesGenerator = PythagoreanTriplesGenerator::getPythagoreanTriplesGenerator();

	while (true)
		std::cout << pythTriplesGenerator() << std::endl;
}