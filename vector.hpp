#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <limits> 
# include <iostream>
# include "colors.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"

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
			typedef typename ft::random_access_iterator<pointer>		iterator;
     		typedef typename ft::random_access_iterator<const_pointer> 	const_iterator;
      		typedef typename ft::reverse_iterator<iterator> 			reverse_iterator;
      		typedef typename ft::reverse_iterator<const_iterator> 		const_reverse_iterator;

// ============================================================================================================

// ======================================== CONSTRUCTORS / DESTRUCTORS ========================================
		
		template< class InputIt >																								// A TESTER (? UNABLE IF INTEGRAL?)
			explicit vector( InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator() ) : _alloc(alloc) {
				_size = distance(first, last);
				_capacity = _size;
				_container = _alloc.allocate(_capacity, 0);
				for (int i = 0; first != last; first++, i++)
					_container[i] = *first;
			}

			vector( const allocator_type &alloc = allocator_type() ) : _size(0), _capacity(0), _alloc(alloc){																			
				_container = _alloc.allocate( 0, 0);
			}
			
//		vector filled in constructor

			explicit vector(const size_type n, const value_type &x = value_type(),
						const allocator_type &alloc = allocator_type()) : _size (n), _capacity(n), _alloc(alloc) {
				_container = _alloc.allocate(n, 0);
				std::uninitialized_fill(_container, _container + _size, x);
			}

		// private vector constructor for extended capacity without init the values

		// private :

		// 	explicit vector(const size_type size, const size_type capacity, const value_type &x = value_type(),
		// 					const allocator_type &alloc = allocator_type()) : _size(size), _capacity(capacity), _alloc(alloc){
		// 		(void)x;
		// 		_container = _alloc.allocate(_capacity, 0);
		// 	}

		public :

// 		copy constructor

			explicit vector(const vector& copy) : _size(copy.size()), _alloc(copy.get_allocator()), _capacity(copy.capacity()){												
				_container = _alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < _size; i++)
					_container[i] = copy[i];
			}

			~vector(){_alloc.deallocate(_container, _capacity);}

			void	assign(size_type count, const T& value){
				vector tmp(count, value);
				*this = tmp;
			}

			template< class InputIt >																// A TESTER (? UNABLE IF INTEGRAL ?)
			void assign( InputIt first, enable_if<is_integral<InputIt>::type>,InputIt last ){
				for (int i = 0; i < _size, first != last; i++, first++)
					_container[i] = *first;
			}


// ===========================================================================================

// ======================================== OPERATOR OVERLOADS ===============================

			reference operator[]( size_type pos )				{return (_container[pos]);}
			const_reference operator[]( size_type pos ) const 	{return (_container[pos]);}                    // A TESTER
			
			vector &operator=(const vector& other){
				_alloc.deallocate(_container, _capacity);
				_size = other.size();
				_capacity = other.capacity();
				_alloc = other.get_allocator();
				_container = _alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < _size; i++)
					_container[i] = other[i];
				return (*this);
			}

// ===========================================================================================

// ======================================== ACCESSORS ========================================


			allocator_type get_allocator() const 	{	return (_alloc);									}

			size_type size() const					{	return (_size);										}
			size_type capacity() const				{	return (_capacity);									}

			reference 		front()					{	return (*_container);								}
			const_reference front() const			{	return (*_container);								}

			reference		back()					{	return (*(_container + _size));						}
			const_reference back()  const			{	return (*(_container + _size));						}

			pointer 		data() 					{	return (_container);								}
			const pointer	data()  const			{	return (_container);								}

// ===========================================================================================

// ======================================== ITERATORS ========================================

			iterator begin()						{	return iterator(_container);						}
			iterator end()							{	return iterator(_container + _size);				}

			const_iterator begin() const 			{	return const_iterator(_container);					}
			const_iterator end() const 				{	return const_iterator(_container + _size);			}

			reverse_iterator rbegin() 				{	return reverse_iterator(_container + _size);		}
			reverse_iterator rend() 				{	return reverse_iterator(_container);				}

			const_reverse_iterator rbegin() const	{	return const_reverse_iterator(_container + _size);	}
			const_reverse_iterator rend() const 	{	return const_iterator(_container);					}

// ===========================================================================================

// ======================================== CAPACITY =========================================

			reference at(size_type pos){
				if (pos > _size)
					throw (std::out_of_range("Index out of bounds"));
				return (_container[pos]);
			}

			const_reference at(size_type pos) const {                                                       // CONST A TESTER
				if (pos > _size)
					throw (std::out_of_range("Index out of bounds"));
				return (_container[pos]);				
			}

			bool		empty()		const		{	return (begin() == end());								}
			size_type max_size() 	const		{	return (std::numeric_limits<difference_type>::max());	}

			void 		push_back(const value_type& value) {

				if (_size +1 < _capacity)
				{
					_container[_size] = value;
					_size++;
				}
				else
				{
					if (_capacity == 0)
						_capacity++;
					reserve(_capacity * 2);
					_container[_size] = value;
					_size++;
				}
			}

			void	reserve(size_type new_cap){
				if (new_cap < _capacity)
					return ;
				if (new_cap > max_size())
					throw (std::length_error("New capacity too big for object size"));
				vector temp(new_cap);
				temp._size = 0;
				for (size_type i = 0; i < _size; i++)
					temp.push_back(_container[i]);
				*this = temp;
			}

// ===========================================================================================

//  ======================================== MODIFIERS =======================================

			void	clear(){																		// A TESTER
				vector tmp(0, _capacity);
				*this = tmp;
			}

			iterator insert( iterator pos, size_type count, const T& value ){
				if (count == 0)
					return (pos);
				int insert_index = distance(begin(), pos);
				if (_size + count >= _capacity)
					reserve(_capacity + count + 1);
				for (int end = _size + count - 1; end >= insert_index + count; end--)
					_container[end] = _container[end - count];
				for (int end = insert_index + count - 1; end >= insert_index; end--)
					_container[end] = value;
	
				_size += count;
				return (begin()+ insert_index);
			}

			iterator insert( iterator pos, const T& value ){									// A TESTER
				size_type insert_index = distance(begin(), pos);
				if (!_size || !insert_index){
					_container[0] = value;
					return (begin());
				}
				if (_size + 1 >= _capacity){
					if (!_capacity)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				for (size_type end = _size; end >= insert_index; end--)
					_container[end] = _container[end - 1];
				_container[insert_index - 1] = value;
				_size++;
				return (begin() + (insert_index - 1));
			}

			template< class InputIt >
			iterator insert( iterator pos, InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last ){
				int insert_index = distance(begin(), pos);
				int count = distance(first, last);
				if (first == last)
					return (pos);
				if (_size + count >= _capacity)
					reserve(_size + count);
				for(int end = _size + count - 1; end >= insert_index + count; end--)
					_container[end] = _container[end - count];		
				last--;
				for (int end = insert_index + count - 1; end >= insert_index; end--, last--)
					_container[end] = *last;		
				_size += count;				
				return (begin() + insert_index);
			}

			void 	pop_back(){
				_alloc.destroy(_container + _size);
				_size--;
			}

			iterator erase( iterator pos ){
				int erase_index = distance(begin(), pos);
				for (int beg = erase_index; beg < erase_index + _size - 1; beg++)
					_container[beg] = _container[beg + 1];
				_size--;
				return (begin() + erase_index);
			}

			iterator erase( iterator first, iterator last ){
				int count = distance(first, last);
				int erase_index = distance(begin(), first);
				if (distance (begin(), last) == _size){
					_size -= count;
					while (first != last){
						_alloc.destroy(first.getPointer());
						first++;
					}
					return (begin() + erase_index);
				}
				for (int beg = erase_index; beg < erase_index < _size - count; beg++)
					_container[beg] = _container[beg + count - 1];
				_size -= count;
				return (begin() + erase_index);
			}

			void resize( size_type count, T value = T() ){
				if (_size > count){
					int tmp = count;
					while (tmp <= _size){
						_alloc.destroy(_container + tmp);
						tmp++;
					}
					_size = count;
					return ;
				}
				else {
					while (_size < count){
						_container[_size] = value;
						_size++;
					}
				}				
			}

		void swap(vector &other){
			std::swap(_container, other._container);
			std::swap(_size, other._size);
			std::swap(_capacity, other._capacity);
		}


// ===========================================================================================

// ========================================== DATA MEMBERS ===================================

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
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T>
	bool operator<=(const vector<T> &lhs, const vector<T> &rhs) {
		return !(lhs > rhs);
	}

	template <typename T>
	bool operator>(const vector<T> &lhs, const vector<T> &rhs) {
		return (rhs < lhs);
	}

	template <typename T>
	bool operator>=(const vector<T> &lhs, const vector<T> &rhs) {
		return !(lhs < rhs);
	}

	template <typename T>
	void swap(vector<T> &lhs, vector<T> &rhs) {
		rhs.swap(lhs);
	}
 
}

#endif