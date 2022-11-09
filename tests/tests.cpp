# include "tests.hpp"

void	vector_tests()
{
	std::cout << MAGENTA << std::endl << "======VECTOR======" << std::endl << std::endl << RESET;
	std::cout << MAGENTA << std::endl << "-----basics-----" << std::endl << std::endl << RESET;


	{
		std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

		refVectorTests ref;
		vectorTests test;
		test.testCopyAssignment();
		test.testCopyConstructor();
		test.testReserve();
		test.testAssign();
		test.testInsert();
		test.testErase();
		test.constItTests();
		test.relational_ope();

		// test.testResize();

		// test.testPopBack();
		std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> fp_ms = end - start; 
		std::cout << CYAN << "VECTOR EXEC TIME : " << fp_ms.count() << std::endl << std::endl;
	}
	{
		std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
		refVectorTests ref;
		refIteratorTests refIt;

		ref.testCopyAssignment();
		ref.testCopyConstructor();
		ref.testReserve();
		ref.testAssign();
		ref.testInsert();
		ref.testErase();
		ref.constItTests();
		ref.relational_ope();

		std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> fp_ms = end - start; 
		std::cout << CYAN<< "REFERENCE EXEC TIME : " << fp_ms.count() << std::endl << std::endl;
	}

}