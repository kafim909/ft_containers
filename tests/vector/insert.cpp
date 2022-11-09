# include "../tests.hpp"

void	vectorTests::testInsert()
{
	vectorUtils u;
	filename = "insert.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	std::cout << std::endl <<YELLOW << "TEST FT::INSERT FUNCTION" << RESET << std::endl << std::endl;

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
		u.printVector(test, 1, file, pos);
		ft::vector<int>::iterator ret = test.insert(pos, to_insert.begin(), to_insert.end());
		u.printVector(test, 2, file, ret);
		if (*ret == 1000 && *(ret + 1) == 2000 && *(ret + 2) == 3000)
			std::cout << GREEN << "TEST OK" << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << std::endl;
	}
	std::cout << BLUE << "INSERT UNIT TESTS 1: CHECK LOG" << RESET << std::endl;{
		file << "TEST INSERT" << std::endl;
		ft::vector<int> vct(10);
		ft::vector<int> vct2;
		ft::vector<int> vct3;
		ft::vector<int>::iterator ret;
		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		u.printVector(vct, 0, file, vct.begin());


		ret = vct2.insert(vct2.end(), 42);
		u.printVector(vct2, 1, file, ret);


		ret = vct2.insert(vct2.begin(), 2, 21);
		u.printVector(vct2, 2, file, ret);

		ret = vct2.insert(vct2.end() - 2, 42);
		u.printVector(vct2, 3, file, ret);

		ret = vct2.insert(vct2.end(), 2, 84);
		u.printVector(vct2, 4, file, ret);

		vct2.resize(4);
		u.printVector(vct2, 5, file, ret);

		ret = vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		u.printVector(vct2, 6, file, ret);

		vct.clear();
		u.printVector(vct2, 7, file, ret);

		for (int i = 0; i < 5; ++i)
			vct3.insert(vct3.end(), i);
		u.printVector(vct2, 8, file, ret);
		ret = vct3.insert(vct3.begin() + 1, 2, 111);
		u.printVector(vct2, 9, file, ret);
	}
}

void	refVectorTests::testInsert()
{
	vectorUtils u;
	filename = "insert_ref.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	std::cout << std::endl << YELLOW << "TEST REF::INSERT FUNCTION" << RESET << std::endl << std::endl;

	std::cout << BLUE << "TEST WITH POS : " << RESET; {
		std::vector<int> test(10, 8);
		std::vector<int>::iterator pos =  test.begin() + 4;
		std::vector<int>::iterator ret = test.insert(pos, 4);
		if (*ret == 4)
			std::cout << GREEN << "TEST OK" << RESET << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << RESET << std::endl;
	}
	std::cout << BLUE << "TEST WITH POS : " << RESET; {
		std::vector<int> test(2, 2);
		std::vector<int>::iterator pos =  test.begin();
		std::vector<int>::iterator ret = test.insert(pos, 500);
		if (*test.begin() == 500)
			std::cout << GREEN << "TEST OK" << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << std::endl;
	}
	std::cout << BLUE << "TEST WITH POS & COUNT : " << RESET; {
		std::vector<int> test;
		std::vector<int>::iterator pos =  test.begin();
		std::vector<int>::iterator ret = test.insert(pos, 2, 10);
		if (*ret == 10 && *(ret + 1) == 10)
			std::cout << GREEN << "TEST OK" << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << std::endl;
	}
	std::cout << BLUE << "TEST WITH ITERATORS : " << RESET; {
		std::vector<int> test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		std::vector<int> to_insert;
		to_insert.push_back(1000);
		to_insert.push_back(2000);
		to_insert.push_back(3000);
		std::vector<int>::iterator pos =  test.begin() + 2;
		u.printVector(test, 1, file, pos);
		std::vector<int>::iterator ret = test.insert(pos, to_insert.begin(), to_insert.end());
		u.printVector(test, 2, file, ret);
		if (*ret == 1000 && *(ret + 1) == 2000 && *(ret + 2) == 3000)
			std::cout << GREEN << "TEST OK" << std::endl;
		else
			std::cout << RED << "TEST NOT OK" << std::endl;
	}
	std::cout << BLUE << "INSERT UNIT TESTS 1: CHECK LOG" << RESET << std::endl;{
		file << "TEST INSERT" << std::endl;
		std::vector<int> vct(10);
		std::vector<int> vct2;
		std::vector<int> vct3;
		std::vector<int>::iterator ret;
		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		u.printVector(vct, 0, file, vct.begin());

		ret = vct2.insert(vct2.end(), 42);
		u.printVector(vct2, 1, file, ret);

		ret = vct2.insert(vct2.begin(), 2, 21);
		u.printVector(vct2, 2, file, ret);

		ret = vct2.insert(vct2.end() - 2, 42);
		u.printVector(vct2, 3, file, ret);

		ret = vct2.insert(vct2.end(), 2, 84);
		u.printVector(vct2, 4, file, ret);

		vct2.resize(4);
		u.printVector(vct2, 5, file, ret);

		ret = vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		u.printVector(vct2, 6, file, ret);

		vct.clear();
		u.printVector(vct2, 7, file, ret);

		for (int i = 0; i < 5; ++i)
			vct3.insert(vct3.end(), i);
		u.printVector(vct2, 8, file, ret);

		ret = vct3.insert(vct3.begin() + 1, 2, 111);
		u.printVector(vct2, 9, file, ret);
	}
}