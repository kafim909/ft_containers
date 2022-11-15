#ifndef TESTS_HPP
# define TESTS_HPP
# include "../vector.hpp"
# include "../colors.hpp"
# include <chrono>
# include <vector>
# include <fstream>
# include <iostream>


# define _VECTOR_LOG_PATH "/Users/mtournay/Desktop/ft_containers/tests/vector/logs/"

struct vectorUtils
{
	template <typename vect, typename it>
	void printVector(vect &to_print, int n, std::ofstream &file, it ret){
		file << std::endl;
		for (it beg = to_print.begin(); beg != to_print.end(); beg++)
			file << n << " - " << *beg << std::endl;
		file << "RETURN VALUE  = " << *ret << std::endl;
		file << "RETURN - BEGIN  = " << ret - to_print.begin() << std::endl;
		file << "SIZE = " << to_print.size() << " CAPACITY = " << to_print.capacity() << std::endl;
	}
};

struct iteratorTests
{
	void constItTests();
	void operatorTests();
};

struct operatorTests
{
	void compTests();
};

struct refIteratorTests
{
	void constItTests();
};

struct vectorTests
{
	std::string filename;

	void	testCopyAssignment();
	void	testCopyConstructor();
	void	testReserve();
	void	testAssign();
	void	testPopBack();
	void	testInsert();
	void	testErase();
	void	testResize();

	void	relational_ope();
	void	testSize();

	void constItTests();
	void operatorTests();
	void reverseIt();
};

struct refVectorTests
{
	std::string filename;

	void	testCopyAssignment();
	void	testCopyConstructor();
	void	testReserve();
	void	testAssign();
	void	testErase();
	void	testInsert();

	void	relational_ope();
	void	testSize();

	void constItTests();
	void operatorTests();
	void reverseIt();
};

void	vector_tests();


#endif