
// Including an external file
// #include ""
// Visual studio will look for files within the project directoy FIRST

// #include <>
// Visual studio will look for files outside the project, but only inside
// the directories specified to look in the Project configuration

// Rule of thumb use double quotes (") to include files that YOU have written
// Use (<>) to include files that you have imported

// #include "gtest/gtest.h"

// Main entry point to our program

#include <gtest/gtest.h>
#include <iostream>

#include <BlackBoxTest.h>

int Factorial(int a) {
	// 5! = 5 * 4 * 3 * 2 * 1
	if (a == 1)
		return 1;

	return a * Factorial(a - 1);
}

TEST(FactorialTests, Factorial) {
	EXPECT_EQ(120, Factorial(5));
	EXPECT_EQ(720, Factorial(6));
	EXPECT_EQ(24, Factorial(4));
}
// 1 1 2 3 5 8 13 21
TEST(FibonacciTests, Fib5) {
	EXPECT_EQ(5, Fibonacci(5));
}

TEST(FibonacciTests, Fib8) {
	EXPECT_EQ(21, Fibonacci(8));
}

TEST(FibonacciTests, FibNegativeOne) {
	EXPECT_EQ(-1, Fibonacci(-1));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();

	return result;	// return success
}