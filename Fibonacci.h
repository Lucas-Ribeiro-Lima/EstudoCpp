#pragma once
#include <string>
#include <unordered_map>
class Fibonacci {
private:
	std::unordered_map<int, int> dp;

public:
	int calc(int n);
};

