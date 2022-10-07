#ifndef ITERATOR_HPP
# define ITERATOR_HPP


namespace ft{

template<	class T,
			class Category,
			class Pointer = T*,
			class Reference = T&>
struct BaseIterator{

	typedef value_type			T;
	typedef iterator_category	Category;
	typedef pointer 			Pointer;
	typedef reference 			Reference;

	using iterator = baseIterator<value_type, iterator_category, pointer, reference>

//============================================ CONSTRUCTORS / DESTRUCTORS

		iterator() 														{					}
		iterator() 														{					}
		iterator(const iterator &copy) 									{	*this = copy	}

//============================================ OPERATOR OVERLOADS

		value_type	&operator*(const iterator &DRF) 					{	return (*ptr);					}
		iterator &operator++()											{	this->ptr++;	return (*this);	}				
		void		&operator++(iterator &increment) 					{	increment.ptr++;				}
		iterator &operator--()											{	this->ptr--;	return (*this);	}				
		void		&operator--(iterator &increment) 					{	increment.ptr--;				}


//============================================ MEMBER VARIABLES

		pointer ptr;
};



























}


#endif