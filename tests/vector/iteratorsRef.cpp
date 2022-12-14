# include "../tests.hpp"

void refIteratorTests::constItTests(){
	std::vector<int> test;
	for (int i = 0; i <= 20; i++)
		test.push_back(i);
	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;
	std::vector<int>::iterator it3;
	std::vector<int>::iterator it4;
	
	std::cout << YELLOW << "TEST PLUS/MINUS" << RESET << std::endl << std::endl;
	std::cout << BLUE << "TEST 1 : " << RESET;{
		it1 = test.begin() + 5;
		it2 = test.begin() + 5;
		it2 -= 2;
		if (*it1 == 5 && *it2 == 3)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST 6 : " << RESET;{
		it1 = test.begin() + 4;
		it3 = it1 - 2;
		if (*it3 == 2)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}

}