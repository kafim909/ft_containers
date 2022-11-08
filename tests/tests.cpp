# include "tests.hpp"

void	vector_tests()
{
	std::cout << MAGENTA << std::endl << "======VECTOR======" << std::endl << std::endl << RESET;
	std::cout << MAGENTA << std::endl << "-----basics-----" << std::endl << std::endl << RESET;


	{
		std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

		vectorTests test;
		test.testCopyAssignment();
		test.testCopyConstructor();
		test.testReserve();
		test.testAssign();
		test.testPopBack();
		test.testInsert();
		test.testErase();
		test.testResize();

		std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> fp_ms = end - start; 
		std::cout << CYAN << "VECTOR EXEC TIME : " << fp_ms.count() << std::endl << std::endl;
	}
	std::cout << MAGENTA << std::endl << "-----iterators-----" << std::endl << std::endl << RESET;
	{

		iteratorTests test;

		test.constItTests();
		std::cout << std::endl << "REF" << std::endl << std::endl;
		refIteratorTests testRef;
		testRef.constItTests();

	}
	std::cout << MAGENTA << std::endl << "-----operators-----" << std::endl << std::endl << RESET;	
	{
		operatorTests test;
		test.compTests();
	}

	// {
	// 	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

	// 	refVectorTests ref;
	// 	ref.testCopyAssignment();
	// 	ref.testCopyConstructor();
	// 	ref.testReserve();
	// // 	ref.testAssign();
	// 	{
	// 		refIteratorTests test;
	// 		test.constItTests();
	// 	}
	// 	std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
	// 	std::chrono::duration<double, std::milli> fp_ms = end - start; 
	// 	std::cout << CYAN<< "REF EXEC TIME : " << fp_ms.count() << std::endl << std::endl;
	// }

}