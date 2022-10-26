#include <iostream>
#include "vector.hpp"
#include "tests/tests.hpp"

int main()
{
	std::cout << MAGENTA << std::endl << "======VECTOR======" << std::endl << std::endl << RESET;
	vectorTests test;
	test.testCopyAssignment();
	test.testCopyConstructor();
}