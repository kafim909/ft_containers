#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator.hpp"


namespace ft {

	template <class T, class iterator = ft::iterator<ft::random_access_iterator_tag, T> >
	class reverse_iterator : public iterator
	{
		typedef T								value_type;
		typedef typename iterator::pointer		pointer;

		public :

			reverse_iterator() 														{					}
			reverse_iterator(pointer op) : ptr(op)									{					}
			reverse_iterator(const reverse_iterator &copy) 							{	*this = copy;	}

			reverse_iterator	&operator=(const reverse_iterator &op)		{	this->ptr = op.ptr; return (*this);	}
			reverse_iterator	&operator=(const pointer op)				{	this->ptr = op; return (*this);		}
			value_type	&operator*(void)		 							{	return (*ptr);						}
			reverse_iterator 	&operator++()								{	this->ptr--;	return (*this);		}					
			void		operator++(int op) 									{	this->ptr--;						}
			reverse_iterator 	&operator--()								{	this->ptr++;	return (*this);		}				
			void		operator--(int op)				 					{	this->ptr++;						}
			bool		operator!=(const reverse_iterator &op)				{	return (this->ptr != op.getPointer());}
			bool		operator==(const reverse_iterator &op)				{	return (this->ptr == op.getPointer());}

			pointer getPointer() const										{	return (ptr);	}

		private :

			pointer ptr;			
	};
}

#endif