#ifndef UTILS_HPP
# define UTILS_HPP
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "random_access_iterator.hpp"

namespace ft {



	template< bool B, class T = void >
	struct enable_if{};
	
	template< class T >
	struct enable_if<true, T>	{	typedef T type;	};

// ===================================

// ================================================================== IS INTEGRAL SFINAE

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






// ====================================


	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
    	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    	{
        	if (*first1 < *first2)
        	    return true;
        	if (*first2 < *first1)
        	    return false;
    	}
 		return (first1 == last1) && (first2 != last2);
	}
}

#endif