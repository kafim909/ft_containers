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
				try {_container = _alloc.allocate( 0, 0);}
				catch (std::bad_alloc &e) {	e.what();}
			}
			
//		vector filled in constructor

			explicit vector(const unsigned int n, const value_type &x = value_type(),
						const allocator_type &alloc = allocator_type()) : _size (n), _alloc(alloc), _capacity(n) {
				try {_container = _alloc.allocate(n, 0);}
				catch (std::bad_alloc &e) {	e.what();}
				std::uninitialized_fill(_container, _container + _size, x);
			}

			explicit vector(const vector& copy) : _size(copy.size()), _alloc(copy.get_allocator()), _capacity(copy.capacity()){												
				iterator beg = copy.begin();
				_container = _alloc.allocate(_capacity, 0);
				for (int i = 0; i < _size; i++)
				{
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
			size_type max_size() const		{return (std::numeric_limits<difference_type>::max());}
			
			value_type& at(size_type n) const {
				if (n < 0 || n > _size)
					throw (std::out_of_range);
				return (_container[n]);
			}

			value_type& front() const 	{return (*_container);}
			value_type& back() const	{return (*(container + _size));}



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