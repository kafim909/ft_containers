#include <iostream>
#include "vector.hpp"

int main()
{
	ft::vector<int> test(10, 5);

	ft::vector<int>::iterator beg = test.begin(); 
	ft::vector<int>::iterator end = test.end(); 

	std::cout << *beg << " " << *end << std::endl;
	
}