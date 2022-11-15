# include "../tests.hpp"

template <class vect>
void	cmp(const vect &lhs, const vect &rhs, std::ofstream &file, int i)
{
	vectorUtils u;
	file << std::endl << "############### [" << i++ << "] ###############"  << std::endl;
	file << "compare this one -> ";
	u.printVector(lhs, i, file, lhs.begin());
	file << "with this one -> ";
	u.printVector(rhs, i, file, rhs.begin());
	file << "equal: " << (lhs == rhs) << " | non equal: " << (lhs != rhs) << std::endl;
	file << "lower: " << (lhs <  rhs) << " | low/equal: " << (lhs <= rhs) << std::endl;
	file << "greater: " << (lhs >  rhs) << " | great/equal: " << (lhs >= rhs) << std::endl;
}

void	vectorTests::relational_ope()
{
	filename = "relational_ope.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	ft::vector<int> vct(4);
	ft::vector<int> vct2(4);

	cmp(vct, vct, file, 0); 
	cmp(vct, vct2, file, 1);

	vct2.resize(10);

	cmp(vct, vct2, file, 2);
	cmp(vct2, vct, file, 3);

	vct[2] = 42;

	cmp(vct, vct2, file, 4);
	cmp(vct2, vct, file, 5);

	swap(vct, vct2);

	cmp(vct, vct2, file, 6);
	cmp(vct2, vct, file, 7);

}

void	refVectorTests::relational_ope()
{
	filename = "relational_ope_ref.txt";
	std::ofstream file(filename.insert(0, _VECTOR_LOG_PATH));
	std::vector<int> vct(4);
	std::vector<int> vct2(4);

	cmp(vct, vct, file, 0); 
	cmp(vct, vct2, file, 1);

	vct2.resize(10);

	cmp(vct, vct2, file, 2);
	cmp(vct2, vct, file, 3);

	vct[2] = 42;

	cmp(vct, vct2, file, 4);
	cmp(vct2, vct, file, 5);

	swap(vct, vct2);

	cmp(vct, vct2, file, 6);
	cmp(vct2, vct, file, 7);

}
