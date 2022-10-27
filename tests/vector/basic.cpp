# include "../tests.hpp"

void vectorTests::testCopyAssignment()
{
	std::cout << YELLOW << "TEST COPY ASSIGNMENT" << RESET << std::endl << std::endl;
	typedef ft::vector<std::string> vect;
	typedef vect::iterator	iter;


	std::cout << BLUE << "TEST 1 : " << RESET; {
		vect test1(5, "coucou");
		vect test2(10, "lol");
		test1 = test2;
		iter end = test1.end();
		int i = 0;
		for (iter beg = test1.begin(); beg != end; beg++){
			if ((*beg).compare("lol"))
				break;
			i++;
		}
		if (i != 10)
			std::cout << RED << "NOT OK" << RESET << std::endl;
		else
			std::cout << GREEN << "OK"  << RESET << std::endl;
	}
	std::cout << BLUE << "TEST 2 : " << RESET; {
		vect test1;
		vect test2(10, "lol");
		test1 = test2;
		test2[4] = "yo";
		iter end = test1.end();
		int i = 0;
		for (iter beg = test1.begin(); beg != end; beg++){
			if ((*beg).compare("lol"))
				break;
			i++;
		}
		if (i != 10)
			std::cout << RED << "NOT OK" << RESET << std::endl;
		else
			std::cout << GREEN << "OK"  << RESET << std::endl;
	}
	std::cout << BLUE << "TEST 3 : " << RESET; {
		vect test1(5, "coucou");
		vect test2;
		test1 = test2;
		iter beg = test1.begin();
		iter end = test1.end();
		if (beg != end)
			std::cout << RED << "NOT OK" << RESET << std::endl;
		else
			std::cout << GREEN << "OK"  << RESET << std::endl;
	}
}

void vectorTests::testCopyConstructor()
{
	std::cout << YELLOW << "TEST COPY CONSTRUCTOR" << RESET << std::endl << std::endl;
	typedef ft::vector<std::string> vect;
	typedef vect::iterator	iter;

	std::cout << BLUE << "TEST 1 : " << RESET; {
		vect test1(10, "lol");
		vect test2(test1);
		iter end = test1.end();
		int i = 0;
		for (iter beg = test1.begin(); beg != end; beg++){
			if ((*beg).compare("lol"))
				break;
			i++;
		}
		if (i != 10)
			std::cout << RED << "NOT OK" << RESET << std::endl;
		else
			std::cout << GREEN << "OK"  << RESET << std::endl;
	}
}

void vectorTests::testReserve()
{
	std::cout << YELLOW << "TEST RESERVE FUNCTION" << RESET << std::endl << std::endl;

	std::cout << BLUE << "TEST INT : " << RESET;{
		ft::vector<int> test(10, 10);
		test.reserve(20);
		if (test.capacity() == 20 && test.size() == 10)
			std::cout << GREEN << "OK" << RESET << std::endl;
		else
			std::cout << RED << "NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST STRING : " << RESET;{
		ft::vector<std::string> test(10, "coucou");
		test.reserve(20);
		int i = -1;
		if (test.capacity() == 20 && test.size() == 10)
		{
			while (++i < 10)
				if (test[i].compare("coucou"))
					break;
		}
		if (i == 10)
			std::cout << GREEN << "OK" << RESET << std::endl;
		else
			std::cout << RED << "NOT OK" << RESET << std::endl;
	}
}

void	vectorTests::testAssign()
{
	std::cout << YELLOW << "TEST ASSIGN FUNCTION" << RESET << std::endl << std::endl;

	std::cout << BLUE << "TEST INT : " << RESET;{
		ft::vector<int> test (10, 10);
		test.assign(5,5);
		if (test.size() == 5)
		{
			int i = -1;
			while (++i < 5)
				if (test[i] != 5)
					break;
			if (i == test.size())
				std::cout << GREEN <<  "TEST OK" << RESET << std::endl;
			else
				std::cout << RED << "TEST NOT OK" << RESET << std::endl;
		}
	}
	std::cout << BLUE << "TEST STRING : " << RESET;{
		ft::vector<std::string> test (10, "coucou");
		test.assign(15,"lol");
		if (test.size() == 15)
		{
			int i = -1;
			while (++i < 15)
				if (test[i].compare("lol"))
					break;
			if (i == test.size())
				std::cout << GREEN <<  "TEST OK" << RESET << std::endl;
			else
				std::cout << RED << "TEST NOT OK" << RESET << std::endl;
		}
	}
}
