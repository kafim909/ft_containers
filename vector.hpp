#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <memory>
# include "colors.hpp"
# include "iterator.hpp"
# include <vector>

namespace ft
{


	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public :

			typedef T                                        value_type;
			typedef Allocator                                allocator_type;
			typedef typename allocator_type::reference       reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::size_type       size_type;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;

//======================================== ITERATOR

			class iterator : public ft::iterator<ft::random_access_iterator_tag, T>
			{
				public :
					iterator() 														{					}
					iterator(pointer op) : ptr(op)									{					}
					iterator(const iterator &copy) 									{	*this = copy;	}


					iterator	&operator=(const iterator &op)			{	this->ptr = op.ptr; return (*this);	}
					iterator	&operator=(const pointer op)			{	this->ptr = op; return (*this);		}
					value_type	&operator*(void)		 				{	return (*ptr);						}
					iterator 	&operator++()							{	this->ptr++;	return (*this);		}					
					void		operator++(int op) 						{	this->ptr++;						}
					iterator 	&operator--()							{	this->ptr--;	return (*this);		}				
					void		operator--(int op)				 		{	this->ptr--;						}
					n + obj
 					obj + n
					pointer getPointer()											{	return (ptr);	}

				private :

					pointer ptr;			
			};

// ======================================== CONSTRUCTORS / DESTRUCTORS


			vector<value_type>(int n, int dedans) : c(new value_type[n]), _size(n) {
				for (int i = 0; i < n; i++)
					c[i] = dedans++;
			}

			// vector<value_type>(){																			
			// 	try {	c = Allocator::allocate( 0, 0);				}
			// 	catch (std::bad_alloc &e) {	e.what();				}
			// }																								//  create an empty vector // size 0
			// vector<value_type>(const unsigned int n){
			// 	try {	c = Allocator::allocate(_size, 0);			}
			// 	catch (std::bad_alloc &e) {	e.what();				}
			// 	std::uninitialized_fill(c, c + _size, 0);
			// }																								//  create a vector initialized with n values of 0
			// vector<value_type>(const unsigned int n, T x){											//	create a vector initialized with n values of x
			// 	try {	c = Allocator::allocate(15, 0);				}
			// 	catch (std::bad_alloc &e) {	e.what();				}
			// }
			// vector<value_type>(const vector& copy){												//  copy constructor

			// }
			// ~vector<value_type>(){}

// ======================================== OPERATOR OVERLOADS

			// vector &operator=(const vector &op){}
			// T &operator[](const unsigned int index){	return (c[index]);	}


					pointer begin(){
						return (c);
					}
					pointer end(){
						return (c + _size - 1);
					}

		private :

			T *c;
			unsigned long long _size;																			// UNDERLAYING CONTAINER																					


	};



}

#endif