#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include "tests/tests.hpp"
#include <vector>

int main()
{
	// vector_tests();

	std::stack<int> yo;
	ft::stack<int> lol;
	for (int i = 0; i < 5; i++)
		lol.push(5 * i);
	std::cout << "STACK TOP" << lol.top() << std::end;
}