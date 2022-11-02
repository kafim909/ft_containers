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

	template< bool is_integral, typename T >
	struct is_integral_res{
		typedef T type;
		static const bool 	value = is_integral;
	};

	template<typename>
	struct is_integral : public is_integral_res<false, bool> {};

	template<>
	struct is_integral<char> : public is_integral_res<true, bool> {};

	template<typename>
	struct is_integral : public is_integral_res<false, bool> {};



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

	template< class InputIt >
	typename ft::iterator_traits<InputIt>::difference_type distance( InputIt first, InputIt last ){
    	typename std::iterator_traits<It>::difference_type result = 0;
    	while (first != last) 
		{
       		++first;
        	++result;
    	}
    	return result;
	}

	template<class It>
	typename std::iterator_traits<It>::difference_type do_distance(It first, It last, std::random_access_iterator_tag) {
    	return (last - first);
	}
 
}

#endif