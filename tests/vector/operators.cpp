# include "../tests.hpp"

void	operatorTests::compTests()
{
	std::cout << YELLOW << "TEST COMPARATORS" << RESET << std::endl << std::endl;
	std::cout << BLUE << "TEST 1 : " << RESET;{
	ft::vector<int> test(4,4);
	ft::vector<int> test2(5,5);
	if (test2 > test)
		std::cout << GREEN << "TEST OK" << RESET << std::endl;
	else
		std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST 2 : " << RESET;{
	ft::vector<int> test2(4,4);
	ft::vector<int> test(5,5);
	if (test2 < test)
		std::cout << GREEN << "TEST OK" << RESET << std::endl;
	else
		std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST 3 : " << RESET;{
	ft::vector<int> test(4,4);
	ft::vector<int> test2(4,4);
	if (test2 == test)
		std::cout << GREEN << "TEST OK" << RESET << std::endl;
	else
		std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST 4 : " << RESET;{
	ft::vector<int> test(4,3);
	ft::vector<int> test2(4,4);
	if (test <= test2)
		std::cout << GREEN << "TEST OK" << RESET << std::endl;
	else
		std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST 5 : " << RESET;{
	ft::vector<int> test(4,8);
	ft::vector<int> test2(4,4);
	if (test >= test2)
		std::cout << GREEN << "TEST OK" << RESET << std::endl;
	else
		std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
}
