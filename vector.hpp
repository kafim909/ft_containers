#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <memory>
# include "colors.hpp"
# include "iterator.hpp"
# include <limits> 

namespace ft
{

	template <class T, class iterator = ft::iterator<ft::random_access_iterator_tag, T> >
	class vectorIterator : public iterator
	{
		typedef T								value_type;
		typedef typename iterator::pointer		pointer;

		public :

			vectorIterator() 											{					}
			vectorIterator(pointer op) : ptr(op)						{					}
			vectorIterator(const vectorIterator &copy) 					{	*this = copy;	}


			vectorIterator	&operator=(const vectorIterator &op)		{	this->ptr = op.ptr; return (*this);	}
			vectorIterator	&operator=(const pointer op)				{	this->ptr = op; return (*this);		}
			value_type	&operator*(void)		 						{	return (*ptr);						}
			vectorIterator 	&operator++()								{	this->ptr++;	return (*this);		}					
			void		operator++(int op) 								{	this->ptr++;						}
			vectorIterator 	&operator--()								{	this->ptr--;	return (*this);		}				
			void		operator--(int op)				 				{	this->ptr--;						}
			bool		operator!=(const vectorIterator &op)			{	return (this->ptr != op.getPointer());}
			bool		operator==(const vectorIterator &op)			{	return (this->ptr == op.getPointer());}

			pointer getPointer() const									{	return (ptr);	}

		private :

			pointer ptr;			
	};


	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public :

			typedef T                                       value_type;
			typedef Allocator                               allocator_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef	value_type&								reference;
			typedef	const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef ft::vectorIterator<value_type>			iterator;

// ======================================== CONSTRUCTORS / DESTRUCTORS

// 		empty vector

			explicit vector(const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc), _capacity(0){																			
				_container = _alloc.allocate( 0, 0);
			}
			
//		vector filled in constructor

			explicit vector(const size_type n, const value_type &x = value_type(),
						const allocator_type &alloc = allocator_type()) : _size (n), _alloc(alloc), _capacity(n) {
				_container = _alloc.allocate(n, 0);
				std::uninitialized_fill(_container, _container + _size, x);
			}

		// vector constructor for extended capacity without init the values

			explicit vector(const size_type size, const size_type capacity, const value_type &x = value_type(),
							const allocator_type &alloc = allocator_type()) : _size(size), _capacity(capacity), _alloc(alloc){
				_container = _alloc.allocate(_capacity, 0);
			}

// 		copy constructor

			explicit vector(const vector& copy) : _size(copy.size()), _alloc(copy.get_allocator()), _capacity(copy.capacity()){												
				iterator beg = copy.begin();
				_container = _alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < _size; i++){
					_container[i] = *beg;
					beg++;
				}
			}

			~vector<value_type>(){_alloc.deallocate(_container, _capacity);}

// ======================================== OPERATOR OVERLOADS


			vector &operator=(const vector& other){
				_alloc.deallocate(_container, _capacity);
				_size = other.size();
				_capacity = other.capacity();
				_alloc = other.get_allocator();
				_container = _alloc.allocate(_capacity, 0);
				iterator beg = other.begin();
				for (int i = 0; i < _size; i++)
				{
					_container[i] = *beg;
					beg++;
				}
				return (*this);
			}

			value_type &operator[](const unsigned int index)	{return (_container[index]);}

// ======================================== ACCESSORS


			allocator_type get_allocator() const 	{return (_alloc);		}
			size_type size() const					{return (_size);		}
			size_type capacity() const				{return (_capacity);	}

			reference 	front() const 	{return (*_container);}
			reference	back() 	const	{return (*(_container + _size));}
			pointer 	data() 	const 	{return (_container);}

			reference at(size_type n) const {
				if (n > _size)
					throw (std::out_of_range("Index out of bounds"));
				return (_container[n]);
			}

			size_type max_size() const		{return (std::numeric_limits<difference_type>::max());}
			

			bool		empty()	const	{return (begin() == end());}

			void 		push_back(const value_type& value) {
				if (_size +1 <= _capacity)
				{
					_container[_size] = value;
					_size++;
				}
				else
				{
					reserve(_capacity * 2);
					_container[_size] = value;
					_size++;
				}
			}

//  ======================================== MEMORY MANAGMENT

			void	assign(size_type count, const T& value){
				vector tmp(count, value);
				*this = tmp;
			}

			void	reserve(size_type new_cap){
				if (new_cap < _capacity)
					return ;
				if (new_cap > max_size())
					throw (std::length_error("New capacity too big for object size"));
				vector temp(0, new_cap, value_type());
				for (size_type i = 0; i < _size; i++)
					temp.push_back(_container[i]);
				*this = temp;
				// temp.~vector();
			}

			// void	clear(){
			// 	vector tmp(0, )
			// }


// ========================================== POINTERS FUNCTIONS


			pointer begin() const {
				return (_container);
			}
			pointer end()const {
				return (_container + _size);
			}

		private :

			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer 		_container;																				


	};



}

#endif