#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include "iterator.hpp"
# include "iterator_traits.hpp"


namespace ft {

	template <typename Iterator>
	class random_access_iterator : public iterator<ft::random_access_iterator_tag, Iterator>
	{
		
		public :
			
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
    		typedef typename iterator_traits<Iterator>::reference 			reference;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			


			random_access_iterator() : _it(){}
			explicit random_access_iterator(const iterator_type &op) : _it(op)	{}
			random_access_iterator(const random_access_iterator &copy) : _it(copy.getPointer()) {}
   			template < typename It >
   			random_access_iterator( const random_access_iterator<It> &copy ) : _it(copy.getPointer()){}

			random_access_iterator	&operator=(const random_access_iterator &op)		{	_it = op._it; return (*this);		}
			template <typename It>
			random_access_iterator &operator=(const random_access_iterator<It> & op)	{	_it = op.getPointer(); return (*this);	}

			value_type	&operator*(void) const		 									{	return (*_it);						}
			value_type	&operator->(void) const											{	return (*_it);						}
			
			random_access_iterator 	&operator++()										{	_it++;	return (*this);		}					
			void		operator++(int) 												{	this->_it++;						}
			random_access_iterator 	&operator--()										{	_it--;	return (*this);		}				
			void		operator--(int)				 									{	this->_it--;						}

			bool		operator!=(const random_access_iterator &op)					{	return (this->_it != op.getPointer());}
			bool		operator==(const random_access_iterator &op)					{	return (this->_it == op.getPointer());}

			const iterator_type &getPointer() const													{	return (_it);	}
 
		private :

			iterator_type _it;			
	};

			template<class T>
		bool operator==( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (lhs.getPointer() == rhs.getPointer());
		}
		
		template<class T>
		bool operator!=( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (lhs.getPointer() != rhs.getPointer());
		}

		template<class T>
		bool operator<( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (lhs.getPointer() < rhs.getPointer());
		}

		template< class T>
		bool operator<=( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (lhs.getPointer() <= rhs.getPointer());
		}

		template<class T>
		bool operator>(  const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (lhs.getPointer() > rhs.getPointer());
		}

		template<class T>
		bool operator>=( const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs ){
			return (lhs.getPointer() >= rhs.getPointer());
		}

		template<class T>
		random_access_iterator<T> operator+(const random_access_iterator<T>& it, typename random_access_iterator<T>::difference_type n){
			return random_access_iterator<T>(it.getPointer() + n);
		}

		template<class T>
		random_access_iterator<T> operator-( typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& it ){
			return random_access_iterator<T>(it.getPointer() - n);
		}

		// template<class T>
		// random_access_iterator<T> operator-( int n){
		// 	return random_access_iterator<T>(it.getPointer() - n);
		// }

		template< class T>
		typename random_access_iterator<T>::difference_type operator-( const random_access_iterator<T>& lhs, 
			const random_access_iterator<T>& rhs ){
				return (rhs.getPointer() - lhs.getPointer());
			}

		template< class T>
		typename random_access_iterator<T>::difference_type operator+( const random_access_iterator<T>& lhs, 
			const random_access_iterator<T>& rhs ){
				return (rhs.getPointer() + lhs.getPointer());
			}

}


#endif