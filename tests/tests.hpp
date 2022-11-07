#ifndef TESTS_HPP
# define TESTS_HPP
# include "../vector.hpp"
# include "../colors.hpp"
# include <chrono>
# include <vector>

struct iteratorTests
{
	void constItTests();
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