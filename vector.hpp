#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <limits> 
# include <iostream>
# include "colors.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public :

			typedef T                                       			value_type;
			typedef Allocator                               			allocator_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef	value_type&											reference;
			typedef	const value_type&									const_reference;
			typedef typename Allocator::pointer							pointer;
			typedef typename Allocator::const_pointer					const_pointer;
			typedef typename ft::random_access_iterator<value_type>		iterator;
     		typedef typename ft::random_access_iterator<const T> 		const_iterator;
      		typedef typename ft::reverse_iterator<iterator> 			reverse_iterator;
      		typedef typename ft::reverse_iterator<const_iterator> 		const_reverse_iterator;

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

		// private vector constructor for extended capacity without init the values

		private :

			explicit vector(const size_type size, const size_type capacity, const value_type &x = value_type(),
							const allocator_type &alloc = allocator_type()) : _size(size), _capacity(capacity), _alloc(alloc){
				_container = _alloc.allocate(_capacity, 0);
			}

		public :

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

			//  ADD ASSIGN WITH INPUT OPERATORS

			void	reserve(size_type new_cap){
				if (new_cap < _capacity)
					return ;
				if (new_cap > max_size())
					throw (std::length_error("New capacity too big for object size"));
				vector temp(0, new_cap, value_type());
				for (size_type i = 0; i < _size; i++)
					temp.push_back(_container[i]);
				*this = temp;
			}

			// CLEAR NEEDS TESTING

			void	clear(){
				vector tmp(0, _capacity);
				*this = tmp;
			}

			void 	pop_back(){
				_alloc.destroy(_container + _size);
				_size--;
			}


// ========================================== POINTERS FUNCTIONS


			iterator begin() const {
				return iterator(_container);
			}
			iterator end()const {
				return iterator(_container + _size);
			}

			reverse_iterator rbegin() const {
				return reverse_iterator(_container + _size);
			}
			reverse_iterator rend()const {
				return reverse_iterator(_container);
			}

			const_iterator cbegin() const {
				return const_iterator(_container);
			}

			const_iterator cend() const {
				return const_iterator(_container + _size);
			}

			const_reverse_iterator crbegin() const {
				return const_reverse_iterator(_container + _size);
			}

			const_reverse_iterator crend() const {
				return const_iterator(_container);
			}

		private :

			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer 		_container;																				


	};

	template< class T, class Alloc >
	bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){
		if (lhs.size() == rhs.size())
		{
			size_t i = -1;
			while (++i < lhs.size)
				if (lhs[i] != rhs[i])
					break;
			if (i == lhs.size())
				return (true);
		}
		return (false);
	}

	template< class T, class Alloc >
	bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){
		if (lhs == rhs)
			return (false);
		return (true);
	}

	template< class T, class Alloc >
	bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){

	}





}

#endif