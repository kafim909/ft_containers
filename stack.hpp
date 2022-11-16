#ifndef STACK_HPP
# define STACK_HPP
# include <memory>
# include <limits> 
# include <iostream>
# include "colors.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"
# include "vector.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> > 
	class stack
	{
		public :

			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference const_reference;

// ============================================================================================================

		protected :
			container_type c;

		public :

// ======================================== CONSTRUCTORS / DESTRUCTORS ========================================

			explicit stack( const Container& cont = Container() ) : c(cont) {}

			stack( stack& other ) : c(other.c) {}

			~stack() {}

// ===========================================================================================

// ======================================== OPERATOR OVERLOADS ===============================

			stack& operator=( const stack& other )	{c = other.c; return *this;}

// ===========================================================================================

// ======================================== ACCESSORS ========================================

		reference top() 						{return (c.back());}
		const_reference top() const 			{return (c.back());}
		bool empty() const						{return (c.empty());}
		size_type size() const					{return (c.size());}
		void push( const value_type& value )	{c.push_back(value);}
		void pop()								{c.pop_back();}

		template< class stack_type, class _Container >
		friend bool operator==( const ft::stack<stack_type,_Container>& lhs, const ft::stack<stack_type,_Container>& rhs ){
			return (lhs.c == rhs.c);
		}

		template< class stack_type, class _Container >
		friend bool operator!=( const ft::stack<stack_type,_Container>& lhs, const ft::stack<stack_type,_Container>& rhs ){
			return (lhs.c != rhs.c);
		}
		template< class stack_type, class _Container >
		friend bool operator<( const ft::stack<stack_type,_Container>& lhs, const ft::stack<stack_type,_Container>& rhs ){
			return (lhs.c < rhs.c);
		}
		template< class stack_type, class _Container >
		friend bool operator>( const ft::stack<stack_type,_Container>& lhs, const ft::stack<stack_type,_Container>& rhs ){
			return (lhs.c > rhs.c);
		}
		template< class stack_type, class _Container >
		friend bool operator<=( const ft::stack<stack_type,_Container>& lhs, const ft::stack<stack_type,_Container>& rhs ){
			return (lhs.c <= rhs.c);
		}
		template< class stack_type, class _Container >
		friend bool operator>=( const ft::stack<stack_type,_Container>& lhs, const ft::stack<stack_type,_Container>& rhs ){
			return (lhs.c >= rhs.c);
		}
	};

}


#endif