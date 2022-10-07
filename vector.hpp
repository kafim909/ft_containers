#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <memory>
# include "colors.hpp"

namespace ft
{

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{

		public :

// ==================================================== CONSTRUCTORS / DESTRUCTORS

			vector<T>(){																			
				try {	c = Allocator::allocate( 0, 0);				}
				catch (std::bad_alloc &e) {	e.what();				}
			}																								//  create an empty vector // size 0
			vector<T>(const unsigned int n){
				try {	c = Allocator::allocate(_size, 0);	}
				catch (std::bad_alloc &e) {	e.what();				}
				std::uninitialized_fill(c, c + _size, 0);
			}																								//  create a vector initialized with n values of 0
			vector<T>(const unsigned int n, T x){											//	create a vector initialized with n values of x
				try {	c = Allocator::allocate(15, 0);	}
				catch (std::bad_alloc &e) {	e.what();				}
			}
			vector<T>(const vector& copy){												//  copy constructor

			}
			~vector<T>(){}

// ==================================================== OPERATOR OVERLOADS

			vector &operator=(const vector &op){}
			T &operator[](const unsigned int index){	return (c[index]);	}

		private :

			T *c;
			unsigned long long _size;																			// UNDERLAYING CONTAINER																					


	};



}

#endif