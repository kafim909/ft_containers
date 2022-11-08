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

void	vectorTests::testPopBack()
{
	std::cout << YELLOW << "TEST POP_BACK FUNCTION" << RESET << std::endl << std::endl;

	std::cout << BLUE << "TEST 1 : " << RESET << std::endl;{
		ft::vector<int> test(10, 10);
		ft::vector<int>::iterator end = test.end();
		test.pop_back();
	}

}

void	vectorTests::testInsert()
{
	std::cout << YELLOW << "TEST INSERT FUNCTION" << RESET << std::endl << std::endl;

	std::cout << BLUE << "TEST WITH POS : " << RESET; {
		ft::vector<int> test(10, 8);
		ft::vector<int>::iterator pos =  test.begin() + 4;
		ft::vector<int>::iterator ret = test.insert(pos, 4);
		if (*ret == 4)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST WITH POS : " << RESET; {
		ft::vector<int> test(2, 2);
		ft::vector<int>::iterator pos =  test.begin();
		ft::vector<int>::iterator ret = test.insert(pos, 500);
		if (*test.begin() == 500)
			std::cout << GREEN << "TEST OK" << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << std::endl;
	}
	std::cout << BLUE << "TEST WITH POS & COUNT : " << RESET; {
		ft::vector<int> test;
		ft::vector<int>::iterator pos =  test.begin();
		ft::vector<int>::iterator ret = test.insert(pos, 2, 10);
		if (*ret == 10 && *(ret + 1) == 10)
			std::cout << GREEN << "TEST OK" << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << std::endl;
	}
	std::cout << BLUE << "TEST WITH ITERATORS : " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		ft::vector<int> to_insert;
		to_insert.push_back(1000);
		to_insert.push_back(2000);
		to_insert.push_back(3000);
		ft::vector<int>::iterator pos =  test.begin() + 2;
		ft::vector<int>::iterator ret = test.insert(pos, to_insert.begin(), to_insert.end());
		if (*ret == 1000 && *(ret + 1) == 2000 && *(ret + 2) == 3000)
			std::cout << GREEN << "TEST OK" << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << std::endl;
	}
}

void	vectorTests::testErase(){
	std::cout << YELLOW << "TEST ERASE FUNCTION" << RESET << std::endl << std::endl;
	std::cout << BLUE << "TEST WITH POS : " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		ft::vector<int>::iterator pos =  test.begin() + 2;
		ft::vector<int>::iterator ret = test.erase(pos);
		if (*ret == 4)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}	
	std::cout << BLUE << "TEST WITH RANGE : " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		
		ft::vector<int>::iterator beg =  test.begin() + 2;
		ft::vector<int>::iterator end =  test.end();
		ft::vector<int>::iterator ret = test.erase(beg, end);
		if (*ret == 3)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}	
	std::cout << BLUE << "TEST ERASE BEGIN " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		ft::vector<int>::iterator ret = test.erase(test.begin());
		if (*ret == 2)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}	

}

void	vectorTests::testResize(){
	std::cout << YELLOW << "TEST RESIZE FUNCTION" << RESET << std::endl << std::endl;
	std::cout << BLUE << "TEST WITHOUT VALUE AND SIZE GREATER THAN COUNT: " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.resize(3);
		if (test.size() == 3)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}			
	std::cout << BLUE << "TEST WITH VALUE AND COUNT GREATER THAN SIZE: " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.resize(8, 6);
		if (test.size() == 8)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}			
	std::cout << BLUE << "TEST WITHOUT VALUE AND COUNT GREATER THAN SIZE: " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.resize(8);
		if (test.size() == 8)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}			
}












