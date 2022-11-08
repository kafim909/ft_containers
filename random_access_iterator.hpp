#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include "iterator.hpp"
# include "iterator_traits.hpp"


namespace ft {

	template <typename T>
	class random_access_iterator : public iterator<ft::random_access_iterator_tag, T>
	{
		
		public :
			
			// typedef Iterator												iterator_type;
			// typedef typename iterator_traits<Iterator>::pointer				pointer;
    		// typedef typename iterator_traits<Iterator>::reference 			reference;
			// typedef typename iterator_traits<Iterator>::value_type			value_type;
			// typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			// typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			
                /* Category of the iterator. */
            typedef typename iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
                
                /* Type of elements pointed. */
            typedef typename iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
                
                /* Type to represent the difference between two iterators. */
            typedef typename iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
                
                /* Type to represent a pointer to an element pointed */
            typedef T*               pointer;
                
                /* Type to represent a reference to an element pointed */
            typedef T&             reference;


			random_access_iterator() : _it(){}
			explicit random_access_iterator(const pointer &op) : _it(op)	{}
			random_access_iterator(const random_access_iterator &copy) : _it(copy.base()) {}
   			template < typename It >
   			random_access_iterator( const random_access_iterator<It> &copy ) : _it(copy.base()){}

			random_access_iterator	&operator=(const random_access_iterator &op)		{	_it = op._it; return (*this);	}
			template <typename It>
			random_access_iterator &operator=(const random_access_iterator<It> & op)	{	_it = op.base(); return (*this);}

			reference	operator*(void) const		 									{	return (*_it);					}
			pointer 	operator->(void) 												{ 	return &(this->operator*()); 	}
			
			random_access_iterator 	&operator++()										{	_it++;	return (*this);			}					
			void		operator++(int) 												{	this->_it++;					}
			random_access_iterator 	&operator--()										{	_it--;	return (*this);			}				
			void		operator--(int)				 									{	this->_it--;					}

			random_access_iterator operator-(difference_type n)				{random_access_iterator tmp(_it - n); *this = tmp; return (*this);}
			random_access_iterator operator+(difference_type n)				{random_access_iterator tmp(_it + n); *this = tmp; return (*this);}
			random_access_iterator operator-=(difference_type n)				{random_access_iterator tmp(_it - n); *this = tmp; return (*this);}
			random_access_iterator operator+=(difference_type n)				{random_access_iterator tmp(_it + n); *this = tmp; return (*this);}

			bool		operator!=(const random_access_iterator &op)					{	return (this->_it != op.base());}
			bool		operator==(const random_access_iterator &op)					{	return (this->_it == op.base());}

			const pointer &base() const													{	return (_it);	}
 
		private :

			pointer _it;			
	};

			template<class T>
		bool operator==( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (*lhs.base() == *rhs.base());
		}
		
		template<class T>
		bool operator!=( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (*lhs.base() != *rhs.base());
		}

		template<class T>
		bool operator<( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (*lhs.base() < *rhs.base());
		}

		template< class T>
		bool operator<=( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (*lhs.base() <= *rhs.base());
		}

		template<class T>
		bool operator>(  const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (*lhs.base() > *rhs.base());
		}

		template<class T>
		bool operator>=( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (*lhs.base() >= *rhs.base());
		}

		template<class T>
		random_access_iterator<T> operator+(const random_access_iterator<T>& it, typename random_access_iterator<T>::difference_type n){
			return random_access_iterator<T>(it.base() + n);
		}

		template<class T>
		random_access_iterator<T> operator-( typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& it ){
			return random_access_iterator<T>(it.base() - n);
		}

		// template<class T>
		// random_access_iterator<T> operator-( const random_access_iterator<T> it, int n ){
		// 	return random_access_iterator<T>(*it.base() - n);
		// }

		template< class T>
		typename random_access_iterator<T>::difference_type operator-( const random_access_iterator<T>& lhs, 
			const random_access_iterator<T>& rhs ){
				return (rhs.base() - lhs.base());
			}

		template< class T>
		typename random_access_iterator<T>::difference_type operator+( const random_access_iterator<T>& lhs, 
			const random_access_iterator<T>& rhs ){
				return (rhs.base() + lhs.base());
			}

}


#endif