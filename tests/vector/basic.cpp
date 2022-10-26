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
