# include "../tests.hpp"

void	vectorTests::testErase(){
	std::cout << YELLOW << "TEST ERASE FUNCTION" << RESET << std::endl << std::endl;
	std::cout << BLUE << "TEST WITH POS : " << RESET; {
		ft::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		ft::vector<int>::iterator ret = test.erase(test.begin() + 2);
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
	std::cout << BLUE << "UNIT TEST ERASE" << RESET;{
		vectorUtils u;
		filename = "erase.txt";
		std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
		file << "TEST ERASE" << std::endl;
		ft::vector<std::string> vct(10);
		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = std::string((vct.size() - i), i + 65);
		ft::vector<std::string> coucou(vct);
		ft::vector<std::string>::iterator it;
		u.printVector(vct, 1, file, vct.begin());
		it = vct.erase(vct.begin() + 2);
		u.printVector(vct, 2, file, it);
		it = vct.erase(vct.begin());
		u.printVector(vct, 3, file, it);
		it = vct.erase(vct.end() - 1);
		u.printVector(vct, 4, file, it);
		it = vct.erase(vct.begin(), vct.begin() + 3);
		u.printVector(vct, 5, file, it);
		it = it = vct.erase(vct.end() - 3, vct.end() - 1);
		u.printVector(vct, 6, file, it);
		vct.push_back("Hello");
		vct.push_back("Hi there");
		u.printVector(vct, 7, file, it);
		it = vct.erase(vct.end() - 3, vct.end());
		u.printVector(vct, 8, file, it);
		vct.push_back("ONE");
		vct.push_back("TWO");
		vct.push_back("THREE");
		vct.push_back("FOUR");
		u.printVector(vct, 9, file, it);
		it = vct.erase(vct.begin(), vct.end());
		u.printVector(vct, 10, file, it);
	}
}

void	refVectorTests::testErase(){
	std::cout << YELLOW << "TEST ERASE FUNCTION" << RESET << std::endl << std::endl;
	std::cout << BLUE << "TEST WITH POS : " << RESET; {
		std::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		std::vector<int>::iterator pos =  test.begin() + 2;
		std::vector<int>::iterator ret = test.erase(pos);
		if (*ret == 4)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}	
	std::cout << BLUE << "TEST WITH RANGE : " << RESET; {
		std::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		
		std::vector<int>::iterator beg =  test.begin() + 2;
		std::vector<int>::iterator end =  test.end();
		std::vector<int>::iterator ret = test.erase(beg, end);
		if (*ret == 3)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}	
	std::cout << BLUE << "TEST ERASE BEGIN " << RESET; {
		std::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		std::vector<int>::iterator ret = test.erase(test.begin());
		if (*ret == 2)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "UNIT TEST ERASE" << RESET;{
		vectorUtils u;
		filename = "erase_ref.txt";
		std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
		file << "TEST ERASE" << std::endl;
		std::vector<std::string> vct(10);
		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = std::string((vct.size() - i), i + 65);
		std::vector<std::string> coucou(vct);
		std::vector<std::string>::iterator it;
		u.printVector(vct, 1, file, vct.begin());
		it = vct.erase(vct.begin() + 2);
		u.printVector(vct, 2, file, it);
		it = vct.erase(vct.begin());
		u.printVector(vct, 3, file, it);
		it = vct.erase(vct.end() - 1);
		u.printVector(vct, 4, file, it);
		it = vct.erase(vct.begin(), vct.begin() + 3);
		u.printVector(vct, 5, file, it);
		it = it = vct.erase(vct.end() - 3, vct.end() - 1);
		u.printVector(vct, 6, file, it);
		vct.push_back("Hello");
		vct.push_back("Hi there");
		u.printVector(vct, 7, file, it);
		it = vct.erase(vct.end() - 3, vct.end());
		u.printVector(vct, 8, file, it);
		vct.push_back("ONE");
		vct.push_back("TWO");
		vct.push_back("THREE");
		vct.push_back("FOUR");
		u.printVector(vct, 9, file, it);
		it = vct.erase(vct.begin(), vct.end());
		u.printVector(vct, 10, file, it);
	}
}