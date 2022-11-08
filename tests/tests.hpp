#ifndef TESTS_HPP
# define TESTS_HPP
# include "../vector.hpp"
# include "../colors.hpp"
# include <chrono>
# include <vector>

struct utility
{
	void	printVector(ft::vector<int>::iterator first, ft::vector<int>::iterator last);
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
	void	testCopyAssignment();
	void	testCopyConstructor();
	void	testReserve();
	void	testAssign();
	void	testPopBack();
	void	testInsert();
	void	testErase();
	void	testResize();
};

struct refVectorTests     								// tests with STL vector to compare output/performance.
{
	void	testCopyAssignment();
	void	testCopyConstructor();
	void	testReserve();
	void	testAssign();
};

void	vector_tests();


#endif