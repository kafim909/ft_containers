# include "../tests.hpp"
template <typename vect>
void	prepost_incdec(vect &vct, std::ofstream &file)
{
	typename vect::iterator it = vct.begin();
	typename vect::iterator it_tmp;

	file << "Pre inc" << std::endl;
	it_tmp = ++it;
	file << *it_tmp << " | " << *it << std::endl;
	file << "Pre dec" << std::endl;
	it_tmp = --it;
	file << *it_tmp << " | " << *it << std::endl;
	file << "Post inc" << std::endl;
	it_tmp = it++;
	file << *it_tmp << " | " << *it << std::endl;		
	file << "Post dec" << std::endl;
	it_tmp = it--;
	file << *it_tmp << " | " << *it << std::endl;
	file << "###############################################" << std::endl;
	}

void vectorTests::constItTests(){
	vectorUtils u;
	filename = "iterators.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));

	std::cout << YELLOW << "ITERATORS FT:: TESTS" << RESET << std::endl << std::endl;

	ft::vector<int> test;
	for (int i = 0; i <= 20; i++)
		test.push_back(i);
	ft::vector<int>::iterator it1;
	ft::vector<int>::iterator it2;
	ft::vector<int>::iterator it3;
	ft::vector<int>::iterator it4;

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
	std::cout << BLUE << "TEST 1 : " << RESET;{
		it2 = test.begin() + 5;
		it2 += 2;
		if (*it1 == 5 && *it2 == 7)
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

	std::cout << YELLOW << "ITERATORS UNIT TESTS : CHECK LOG" << RESET << std::endl << std::endl;{

		const int size = 5;
		ft::vector<int> vct(size);
		ft::vector<int>::iterator it = vct.begin();
		ft::vector<int>::const_iterator ite = vct.begin();


		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;
		prepost_incdec(vct, file);

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		file<< *(it += 2) << std::endl;
		file << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		file << "const_ite +=: " << *(ite += 2) << std::endl;
		file << "const_ite -=: " << *(ite -= 2) << std::endl;

		file << "(it == const_it): " << (ite == it) << std::endl;
		file << "(const_ite - it): " << (ite - it) << std::endl;
		file << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
	}
}

void	refVectorTests::constItTests()
{
	vectorUtils u;
	filename = "iterators_ref.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));

	std::cout << YELLOW << "ITERATORS REF:: TESTS" << RESET << std::endl << std::endl;

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
	std::cout << BLUE << "TEST 1 : " << RESET;{
		it2 = test.begin() + 5;
		it2 += 2;
		if (*it1 == 5 && *it2 == 7)
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

	std::cout << YELLOW << "ITERATORS UNIT TESTS : CHECK LOG" << RESET << std::endl << std::endl;{

		const int size = 5;
		std::vector<int> vct(size);
		std::vector<int>::iterator it = vct.begin();
		std::vector<int>::const_iterator ite = vct.begin();


		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;
		prepost_incdec(vct, file);

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		file<< *(it += 2) << std::endl;
		file << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		file << "const_ite +=: " << *(ite += 2) << std::endl;
		file << "const_ite -=: " << *(ite -= 2) << std::endl;

		file << "(it == const_it): " << (ite == it) << std::endl;
		file << "(const_ite - it): " << (ite - it) << std::endl;
		file << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
	}
}