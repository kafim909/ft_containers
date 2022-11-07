# include "../tests.hpp"

void refIteratorTests::constItTests(){
	std::vector<std::string> test;
	test.push_back("coucou");
	test.push_back(" comment");
	test.push_back(" ca");
	test.push_back(" va?");
	std::vector<std::string>::iterator it1 = test.begin();
	std::vector<std::string>::iterator it2 = test.begin() + 1;
	std::vector<std::string>::iterator it3 = test.begin() + 2;
	std::vector<std::string>::iterator it4 = test.begin() + 3;
	std::vector<std::string>::const_iterator constIt1 = test.begin();
	std::vector<std::string>::const_iterator constIt2 = test.begin() + 1;
	std::vector<std::string>::const_iterator constIt3 = test.begin() + 2;
	std::vector<std::string>::const_iterator constIt4 = test.begin() + 3;

	constIt1 = constIt2;
	if (constIt1 == constIt2)
		it2 = it3;
	
	if (constIt1 > constIt4)
		it3 = it2;
    std::cout << "const pointer = " << *constIt4 << std::endl;
	constIt4--;
    std::cout << "const pointer = " << *constIt4 << std::endl;
}