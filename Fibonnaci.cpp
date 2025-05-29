#include "Fibonacci.h"

int Fibonacci::calc(int n) {
	if (n < 2) return  n;

	if (dp.find(n) == dp.end()) {
		dp[n] = calc(n - 1) + calc(n - 2);
	}

	return dp[n];
}