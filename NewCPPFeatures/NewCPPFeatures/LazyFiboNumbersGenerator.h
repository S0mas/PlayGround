#pragma once
#include <functional>

class FiboSeqGenerator {
	static auto getFiboGenerator(const unsigned long long f1, const unsigned long long f2) {
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
		unsigned long long f1 = 0;
		unsigned long long f2 = 1;
		unsigned long long result = 0;
		for (auto i = 1; i < startId; ++i) {
			result = f1 + f2;
			f1 = f2;
			f2 = result;
		}
		return getFiboGenerator(f1, f2);
	}
};

class FiboGen {
	//Returns first fib seq number and sets next_ object to function getSecond()
	int getFirst() const {
		next_ = [this]() {
			return getSecond();
		};
		return 0;
	}

	//Returns second fib seq number and sets next_ object to fibo numbers generation algorithm
	int getSecond() const {
		next_ = [f1 = 0, f2 = 1]() mutable {
			auto const nextFibo = f1 + f2;
			f1 = f2;
			f2 = nextFibo;
			return nextFibo;
		};
		return 1;
	}

	mutable std::function<int()> next_ = [this]() {
		return this->getFirst();
	};
public:
	int operator()() const {
		return next_();
	}
};

