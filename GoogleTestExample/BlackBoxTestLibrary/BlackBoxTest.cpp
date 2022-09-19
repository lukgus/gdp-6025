#include "BlackBoxTest.h"
#include "pch.h"

// F = Fibonacci
// F(4) = F(3) + F(2)
// F(3) = F(2) + F(1)
// F(2) = 1
// F(1) = 1

// 1 1 2 3 5 8 13 21 34 ...
int Fibonacci(int v) {
	if (v <= 0)
		return -1;

	if (v == 1 || v == 2)
		return 1;

	return Fibonacci(v - 1) + Fibonacci(v - 2);
}