#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include "iterator.hpp"


namespace ft {

	template <class T, class iterator = ft::iterator<ft::random_access_iterator_tag, T> >
	class random_access_iterator : public iterator
	{
		typedef T								value_type;
		typedef typename iterator::pointer		pointer;

		public :

			random_access_iterator() 											{					}
			random_access_iterator(pointer op) : ptr(op)						{					}
			random_access_iterator(const random_access_iterator &copy) 					{	*this = copy;	}


			random_access_iterator	&operator=(const random_access_iterator &op)	{	this->ptr = op.ptr; return (*this);	}
			random_access_iterator	&operator=(const pointer op)					{	this->ptr = op; return (*this);		}
			value_type	&operator*(void)		 									{	return (*ptr);						}
			value_type	&operator->(void)		 									{	return (*ptr);						}
			random_access_iterator 	&operator++()									{	this->ptr++;	return (*this);		}					
			void		operator++(int op) 											{	this->ptr++;						}
			random_access_iterator 	&operator--()									{	this->ptr--;	return (*this);		}				
			void		operator--(int op)				 							{	this->ptr--;						}
			bool		operator!=(const random_access_iterator &op)					{	return (this->ptr != op.getPointer());}
			bool		operator==(const random_access_iterator &op)					{	return (this->ptr == op.getPointer());}

			pointer getPointer() const												{	return (ptr);	}

		private :

			pointer ptr;			
	};
}


#endif