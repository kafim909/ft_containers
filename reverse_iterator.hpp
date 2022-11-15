#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator.hpp"
# include "iterator_traits.hpp"


namespace ft {

	template <class Iter>
	class reverse_iterator
	{
		public :
		typedef Iter														iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category		iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type				value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type			difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer					pointer;
		typedef typename ft::iterator_traits<Iter>::reference				reference;


// ================================ CONSTRUCTORS / DESCTRUCTOR
			
			reverse_iterator(){}

			explicit reverse_iterator(iterator_type x) : _current(x) {}

			template< class U >
			reverse_iterator(const reverse_iterator<U>& other) {this->_current = other.base();}

// ================================ MEMBER OPERATORS

			reverse_iterator 	&operator++()				{	--_current;	return (*this);		}					
			reverse_iterator 	&operator--()				{	++_current;	return (*this);		}

			reverse_iterator	operator++( int ) 			{	reverse_iterator tmp(*this); --_current; return (tmp);}
			reverse_iterator	operator--( int ) 			{	reverse_iterator tmp(*this); ++_current; return (tmp);}

			reverse_iterator operator+( difference_type n ) const {	return reverse_iterator(base() - n);	}
			reverse_iterator operator-( difference_type n ) const {	return reverse_iterator(base() + n);	}

			reverse_iterator& operator+=( difference_type n ) {	_current -= n; return (*this); };
			reverse_iterator& operator-=( difference_type n ) {	_current += n; return (*this); };		

			template< class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other ){ 
				_current = other.base(); return (*this);
			}

			reference operator*() const 					{ 	Iter tmp = _current; return *--tmp;	}
			pointer operator->() const						{	return &(operator*());					}

			reference operator[] (difference_type n) const	{	return (base()[-n-1]);	}

// ================================ ACCESSORS 

			iterator_type base() const						{	return (_current);		}


		protected :

			iterator_type _current;

	};
			

// ================================ NON MEMBER OPERATORS

		template< class Iterator1, class Iterator2 >
		bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
			return (lhs.base() == rhs.base());
		}
		
		template< class Iterator1, class Iterator2 >
		bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
			return (lhs.base() != rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
			return (lhs.base() > rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
			return (lhs.base() >= rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
			return (lhs.base() < rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
			return (lhs.base() <= rhs.base());
		}

		template< class Iter >
		reverse_iterator<Iter> operator+( typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter>& it ){
			return reverse_iterator<Iter>(it.base() - n);
		}

		template< class T>
		typename reverse_iterator<T>::difference_type operator-( const ft::reverse_iterator<T>& lhs, 
			const ft::reverse_iterator<T>& rhs ){
				return (rhs.base() - lhs.base());
			}

		template< class T>
		typename ft::reverse_iterator<T>::difference_type operator+( const ft::reverse_iterator<T>& lhs, 
			const ft::reverse_iterator<T>& rhs ){
				return (rhs.base() + lhs.base());
			}

		template< class T, class U >
		typename ft::reverse_iterator<T>::difference_type operator-( const ft::reverse_iterator<T>& lhs, 
			const ft::reverse_iterator<U>& rhs ){
				return (rhs.base() - lhs.base());
			}

		template< class T, class U>
		typename ft::reverse_iterator<T>::difference_type operator+( const ft::reverse_iterator<T>& lhs, 
			const ft::reverse_iterator<U>& rhs ){
				return (lhs.base() + rhs.base());
			}

}

#endif