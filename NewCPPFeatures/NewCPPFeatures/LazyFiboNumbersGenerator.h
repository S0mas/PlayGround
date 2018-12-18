#pragma once

class FiboSeqGenerator {
	static auto getFiboGenerator(const int f1, const int f2) {
		return [f1 = f1, f2 = f2, first = true, second = true]() mutable {
			if (first) {
				first = false;
				return f1;
			}
			if (second) {
				second = false;
				return f2;
			}
			auto const next = f1 + f2;
			f1 = f2;
			f2 = next;
			return next;
		};
	}
public:
	static auto getFiboGenerator(const int startId) {
		auto f1 = 0;
		auto f2 = 1;
		auto result = 0;
		for (auto i = 1; i < startId; ++i) {
			result = f1 + f2;
			f1 = f2;
			f2 = result;
		}
		return getFiboGenerator(f1, f2);
	}
};

