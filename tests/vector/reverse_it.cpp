# include "../tests.hpp"

void	vectorTests::reverseIt()
{
	vectorUtils u;
	filename = "reverse_it.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::iterator it_ = vct.begin();
	ft::vector<int>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	u.printVector(vct, 1, file, vct.begin());

	file << (it_ == it.base()) << std::endl;
	file << (it_ == (it + 3).base()) << std::endl;

	file << *(it.base() + 1) << std::endl;
	file << *(it - 3) << std::endl;
	file << *(it - 3).base() << std::endl;
	it -= 3;
	file << *it.base() << std::endl;

	file << "TEST OFFSET" << std::endl;
	file << *(it) << std::endl;
	file << *(it).base() << std::endl;
	file << *(it - 0) << std::endl;
	file << *(it - 0).base() << std::endl;
	file << *(it - 1).base() << std::endl;

	it = vct.rbegin();
	ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	file << *(it += 2) << std::endl;
	file << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	file << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	file << "(it == const_it): " << (ite == it) << std::endl;
	file << "(const_ite - it): " << (ite - it) << std::endl;
	file << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	u.printVector(vct, 2, file, vct.begin());

	it = vct.rbegin();
	ite = vct.rend();

	for (int i = 1; it != ite; ++i){
		*it++ = (i * 7);
		file << "ICI" << std::endl;
	}
	u.printVector(vct, 3, file, vct.begin());

	it = vct.rbegin();
	ite = vct.rbegin();

	file << *(++ite) << std::endl;
	file << *(ite++) << std::endl;
	file << *ite++ << std::endl;
	file << *++ite << std::endl;

	file << *(++it) << std::endl;
	file << *(it++) << std::endl;
	file << *it++ << std::endl;
	file << *++it << std::endl;

	file << *(--ite) << std::endl;
	file << *(ite--) << std::endl;
	file << *--ite << std::endl;
	file << *ite-- << std::endl;

	file << *(--it) << std::endl;
	file << *(it--) << std::endl;
	file << *it-- << std::endl;
	file << *--it << std::endl;
}

void	refVectorTests::reverseIt()
{
	vectorUtils u;
	filename = "reverse_it_ref.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	const int size = 5;
	std::vector<int> vct(size);
	std::vector<int>::iterator it_ = vct.begin();
	std::vector<int>::reverse_iterator it(it_);

	*it_;
	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	u.printVector(vct, 1, file, vct.begin());

	file << (it_ == it.base()) << std::endl;
	file << (it_ == (it + 3).base()) << std::endl;

	file << *(it.base() + 1) << std::endl;
	file << *(it - 3) << std::endl;
	file << *(it - 3).base() << std::endl;
	it -= 3;
	file << *it.base() << std::endl;

	file << "TEST OFFSET" << std::endl;
	file << *(it) << std::endl;
	file << *(it).base() << std::endl;
	file << *(it - 0) << std::endl;
	file << *(it - 0).base() << std::endl;
	file << *(it - 1).base() << std::endl;

	it = vct.rbegin();
	std::vector<int>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	file << *(it += 2) << std::endl;
	file << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	file << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	file << "(it == const_it): " << (ite == it) << std::endl;
	file << "(const_ite - it): " << (ite - it) << std::endl;
	file << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	u.printVector(vct, 2, file, vct.begin());

	it = vct.rbegin();
	ite = vct.rend();

	for (int i = 1; it != ite; ++i){
		*it++ = (i * 7);
		file << "ICI" << std::endl;
	}
	u.printVector(vct, 3, file, vct.begin());

	it = vct.rbegin();
	ite = vct.rbegin();

	file << *(++ite) << std::endl;
	file << *(ite++) << std::endl;
	file << *ite++ << std::endl;
	file << *++ite << std::endl;

	file << *(++it) << std::endl;
	file << *(it++) << std::endl;
	file << *it++ << std::endl;
	file << *++it << std::endl;

	file << *(--ite) << std::endl;
	file << *(ite--) << std::endl;
	file << *--ite << std::endl;
	file << *ite-- << std::endl;

	file << *(--it) << std::endl;
	file << *(it--) << std::endl;
	file << *it-- << std::endl;
	file << *--it << std::endl;
}