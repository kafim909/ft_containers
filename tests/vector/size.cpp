# include "../tests.hpp"

template <typename vect>
void	is_empty(vect const &vct, std::ostream &file)
{
	file << "is_empty: " << vct.empty() << std::endl;
}

void	vectorTests::testSize()
{
	vectorUtils u;
	filename = "size.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	const int start_size = 7;
	ft::vector<int> vct(start_size, 20);
	ft::vector<int> vct2;
	ft::vector<int>::iterator it = vct.begin();
	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	u.printVector(vct, 1, file, vct.begin());
	vct.resize(10, 42);
	u.printVector(vct, 1, file, vct.begin());
	vct.resize(18, 43);
	u.printVector(vct, 2, file, vct.begin());
	vct.resize(10);
	u.printVector(vct, 3, file, vct.begin());
	vct.resize(23, 44);
	u.printVector(vct, 4, file, vct.begin());
	vct.resize(5);
	u.printVector(vct, 5, file, vct.begin());
	vct.reserve(5);
	vct.reserve(3);
	u.printVector(vct, 6, file, vct.begin());
	vct.resize(87);
	vct.resize(5);
	u.printVector(vct, 7, file, vct.begin());
	is_empty(vct2, file);
	vct2 = vct;
	u.printVector(vct2, 8, file, vct2.begin());
	is_empty(vct2, file);
	vct.reserve(vct.capacity() + 1);
	u.printVector(vct, 9, file, vct.begin());
	u.printVector(vct2, 10, file, vct2.begin());
	vct2.resize(0);
	is_empty(vct2, file);
	u.printVector(vct2, 11, file, vct.begin());
}

void refVectorTests::testSize()
{
	vectorUtils u;
	filename = "size_ref.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	const int start_size = 7;
	std::vector<int> vct(start_size, 20);
	std::vector<int> vct2;
	std::vector<int>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	u.printVector(vct, 1, file, vct.begin());

	vct.resize(10, 42);
	u.printVector(vct, 1, file, vct.begin());
	vct.resize(18, 43);
	u.printVector(vct, 2, file, vct.begin());
	vct.resize(10);
	u.printVector(vct, 3, file, vct.begin());
	vct.resize(23, 44);
	u.printVector(vct, 4, file, vct.begin());
	vct.resize(5);
	u.printVector(vct, 5, file, vct.begin());
	vct.reserve(5);
	vct.reserve(3);
	u.printVector(vct, 6, file, vct.begin());
	vct.resize(87);
	vct.resize(5);
	u.printVector(vct, 7, file, vct.begin());
	is_empty(vct2, file);
	vct2 = vct;
	u.printVector(vct2, 8, file, vct2.begin());
	is_empty(vct2, file);
	vct.reserve(vct.capacity() + 1);
	u.printVector(vct, 9, file, vct.begin());
	u.printVector(vct2, 10, file, vct2.begin());
	vct2.resize(0);
	is_empty(vct2, file);
	u.printVector(vct2, 11, file, vct.begin());
}