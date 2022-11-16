#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <limits> 
# include <iostream>
# include "colors.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"

static class nullptr_t
{
    public:
        template<class T>
        operator T*() const { return (0); }

        template<class C, class T>
        operator T C::*() const { return (0); }

    private:
        
        void operator&() const;

} u_nullptr = {};

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
														
		public :

			typedef T                                       				value_type;
			typedef Allocator                               				allocator_type;
			typedef std::size_t												size_type;
			typedef	value_type&												reference;
			typedef	const value_type&										const_reference;
			typedef typename Allocator::pointer								pointer;
			typedef typename Allocator::const_pointer						const_pointer;
			typedef typename Allocator::difference_type						difference_type;
			typedef typename ft::random_access_iterator<value_type>			iterator;
     		typedef typename ft::random_access_iterator<const value_type>	 	const_iterator;
      		typedef typename ft::reverse_iterator<iterator> 				reverse_iterator;
      		typedef typename ft::reverse_iterator<const_iterator> 			const_reverse_iterator;

// ============================================================================================================
		
		private :

			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer 		_container;

// ======================================== CONSTRUCTORS / DESTRUCTORS ========================================

		public :

		explicit vector( const allocator_type &alloc = allocator_type() ) : _size(0), _capacity(0), _alloc(alloc){_container = _alloc.allocate(_capacity);}

		template< class InputIt >																								
			explicit vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = u_nullptr ) : _alloc(alloc) {
				_size = ft::distance(first, last);
				_capacity = _size;
				_container = _alloc.allocate(_capacity);
				for (int i = 0; first != last; first++, i++)
					_container[i] = *first;
			}

			explicit vector(const size_type n, const value_type &x = value_type(),
						const allocator_type &alloc = allocator_type()) : _size (n), _capacity(n), _alloc(alloc) {
				_container = _alloc.allocate(n);
				std::uninitialized_fill(_container, _container + _size, x);
			}

			explicit vector(const vector& copy) : _size(copy.size()), _capacity(copy.capacity()), _alloc(copy.get_allocator()){												
				_container = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_container[i] = copy[i];
			}

			~vector(){if(_capacity){_alloc.deallocate(_container, _capacity);}}

// ===========================================================================================

// ======================================== FILL FUNCTIONS  ==================================

			void	assign(size_type count, const T& value){
				this->clear();
				if (count > this->_capacity)
				{
					_alloc.deallocate(_container, _capacity);
					_container = _alloc.allocate(count);
					_capacity = count;
				}
				for (size_type i = 0; i < count; i++)
					_container[i] = value;
				_size = count;
			}

			template< class InputIt >																
			void assign( InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = u_nullptr ){
				size_type dist = ft::distance(first,last);
				clear();
				if (dist > this->_capacity)
				{
					this->_alloc.deallocate(this->_container, this->_capacity);
					this->_container = this->_alloc.allocate(dist);
					this->_capacity = dist;
				}
				for (size_type i = 0; i < dist; i++, first++)
					this->_alloc.construct(this->_container + i, *first);
				this->_size = dist;
			}


// ===========================================================================================

// ======================================== OPERATOR OVERLOADS ===============================

			reference operator[]( size_type pos )				{return (_container[pos]);}
			const_reference operator[]( size_type pos ) const 	{return (_container[pos]);}                    // A TESTER
			
			vector &operator=(const vector& other){
				_alloc.deallocate(_container, _capacity);
				_size = other.size();
				_capacity = other.size();
				_alloc = other.get_allocator();
				_container = _alloc.allocate(_size, 0);
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

			reference		back()					{	return (*(_container + (_size - 1)));						}
			const_reference back()  const			{	return (*(_container + (_size - 1)));						}

			pointer 		data() 					{	return (_container);								}
			const pointer	data()  const			{	return (_container);								}

// ===========================================================================================

// ======================================== ITERATORS ========================================

			iterator begin()						{	return iterator(_container);						}
			iterator end()							{	return iterator(_container + _size);				}

			const_iterator begin() const 			{	return const_iterator(_container);					}
			const_iterator end() const 				{	return const_iterator(_container + _size);			}

			reverse_iterator rbegin() 				{	return reverse_iterator(this->end());		}
			reverse_iterator rend() 				{	return reverse_iterator(this->begin());				}

			const_reverse_iterator rbegin() const	{	return const_reverse_iterator(this->end());	}
			const_reverse_iterator rend() const 	{	return const_iterator(this->begin());					}

// ===========================================================================================

// ======================================== CAPACITY =========================================

			reference at(size_type pos){
				if (pos >= _size)
					throw (std::out_of_range("Index out of bounds"));
				return (_container[pos]);
			}

			const_reference at(size_type pos) const {                                                       // CONST A TESTER
				if (pos >= _size)
					throw (std::out_of_range("Index out of bounds"));
				return (_container[pos]);				
			}

			bool		empty()		const		{	return (begin() == end());								}
			size_type max_size() 	const		{	return (_alloc.max_size());	}

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
				if (new_cap > this->max_size())
					throw std::out_of_range("vector::reserve");
				else if (this->_capacity >= new_cap)
					return ;
				pointer tmp = this->_alloc.allocate(new_cap);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(tmp + i, this->_container[i]);
					this->_alloc.destroy(this->_container + i);
				}
				this->_alloc.deallocate(this->_container, this->_capacity);
				this->_container = tmp;
				this->_capacity = new_cap;
			}

// ===========================================================================================

//  ======================================== MODIFIERS =======================================

			void	clear(){																		// A TESTER
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_container + i);
				_size = 0;
			}

			iterator insert( iterator pos, size_type count, const T& value ){
				if (count == 0)
					return (pos);
				size_type insert_index = ft::distance(begin(), pos);   
				if (_size + count > _capacity)
				{
					reserve(_capacity * 2);
					if (_size + count > _capacity)
						reserve(_size + count);
				}

				for (size_type end = _size + count - 1; end >= insert_index + count; end--)
					_container[end] = _container[end - count];

				for (size_type end = insert_index + count - 1; end >= insert_index && end <= _size + count; end--)
					_container[end] = value;
	
				_size += count;
				return (begin()+ insert_index);
			}

			iterator insert( iterator pos, const T& value ){							
				size_type insert_index = ft::distance(begin(), pos);
				if (_size + 1 > _capacity){
					if (!_capacity)
						reserve(1);
					else
						reserve(_capacity + 1);
				}
				if (!_size){
					_container[0] = value;
					_size++;
					return (begin());
				}
				for (size_type end = _size; end > insert_index; end--)
					_container[end] = _container[end - 1];
				_container[insert_index] = value;
				_size++;
				return (begin() + (insert_index));
			}

			template< class InputIt >
			iterator insert( iterator pos, InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = u_nullptr){
				int insert_index = ft::distance(begin(), pos);
				int count = ft::distance(first, last);
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
				int erase_index = ft::distance(begin(), pos);
				_alloc.destroy(pos.base());
				for (size_type beg = erase_index; beg < _size - 1; beg++)
					_container[beg] = _container[beg + 1];
				_size--;
				return (begin() + erase_index);
			}

			iterator erase( iterator first, iterator last ){
				size_type count = ft::distance(first, last);
				int erase_index = ft::distance(begin(), first);
				if (ft::distance (first, last) == _size){
					_size -= count;
					while (first != last){
						_alloc.destroy(first.base());
						first++;
					}
					return (begin() + erase_index);
				}
				for (size_type beg = erase_index; beg < _size - count; beg++) // erase_index = 0; size = 7; count = 3;
					_container[beg] = _container[beg + count];
				_size -= count;
				return (begin() + erase_index);
			}

			void resize( size_type count, T value = T() ){
				if (count > _capacity)
				{
					reserve(_capacity * 2);
					if (count > _capacity)
						reserve(count);
				}
				if (_size > count){
					size_type tmp = count;
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

	};

	template< class T, class Alloc >
	bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		if (lhs.size() == rhs.size())
		{
			size_t i = -1;
			while (++i < lhs.size())
				if (lhs[i] != rhs[i])
					break;
			if (i == lhs.size())
				return (true);
		}
		return (false);
	}

	template< class T, class Alloc >
	bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T>
	bool operator<=(const vector<T> &lhs, const vector<T> &rhs) {
		if (lhs == rhs || lhs < rhs)
			return (true);
		return (false);
	}

	template <typename T>
	bool operator>(const vector<T> &lhs, const vector<T> &rhs) {
		return (rhs < lhs);
	}

	template <typename T>
	bool operator>=(const vector<T> &lhs, const vector<T> &rhs) {
		if (lhs == rhs || lhs > rhs)
			return (true);
		return (false);
	}

	template <typename T>
	void swap(vector<T> &lhs, vector<T> &rhs) {
		rhs.swap(lhs);
	}
 
}

#endif