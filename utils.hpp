#ifndef UTILS_HPP
# define UTILS_HPP
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "random_access_iterator.hpp"
# include <type_traits>

namespace ft {



	template< bool B, class T = void >
	struct enable_if{};
	
	template< class T >
	struct enable_if<true, T>	{	typedef T type;	};

// ============================================================================================================

// ============================================================================================================

	template<typename>
	struct is_integral									{	static const bool 	value = false;	};
	template<>
	struct is_integral<char>							{	static const bool 	value = true;	};
	template<>
	struct is_integral<bool>							{	static const bool 	value = true;	};
	template<>
	struct is_integral<signed char>						{	static const bool 	value = true;	};
	template<>
	struct is_integral<short int>						{	static const bool 	value = true;	};
	template<>
	struct is_integral<int>								{	static const bool 	value = true;	};
	template<>
	struct is_integral<long int>						{	static const bool 	value = true;	};
	template<>
	struct is_integral<long long int>					{	static const bool 	value = true;	};
	template<>
	struct is_integral<unsigned char>					{	static const bool 	value = true;	};
	template<>
	struct is_integral<unsigned short int>				{	static const bool 	value = true;	};
	template<>
	struct is_integral<unsigned int>					{	static const bool 	value = true;	};
	template<>
	struct is_integral<unsigned long int>				{	static const bool 	value = true;	};
	template<>
	struct is_integral<unsigned long long int>			{	static const bool 	value = true;	};



// ============================================================================================================

// ============================================================================================================

	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
    	for (; (first1 != last1) && (first2 != last2); first1++, first2++)
    	{
        	if (*first1 < *first2)
        	    return true;
        	if (*first2 < *first1)
        	    return false;
    	}
 		return (first2 != last2);
	}

// ============================================================================================================

// ============================================================================================================

	template <class T1, class T2> 
	struct pair
	{
		public :

			typedef T1 first_type;
			typedef T2 second_type;

			pair() : first(T1()), second(T2()) {}

			pair( const T1& x, const T2& y ) : first(x), second(y) {}

			template< class U1, class U2 >
			pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}

			T1	first;
			T2	second;

	};


	
}

#endif