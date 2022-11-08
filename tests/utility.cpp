# include "tests.hpp"

void	utility::printVector(ft::vector<int>::iterator first, ft::vector<int>::iterator last)
	{
		std::cout << RED << "PRINT VECTOR : " << RESET << std::endl;
		while (first != last)
		{
			std::cout << *first << std::endl;
			first++;
		}
	}	