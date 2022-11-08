#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iostream>

namespace ft{

template <class Iter>
    struct iterator_traits {
        typedef typename Iter::value_type            value_type;
        typedef typename Iter::difference_type       difference_type;
        typedef typename Iter::iterator_category     iterator_category;
        typedef typename Iter::pointer               pointer;
        typedef typename Iter::reference             reference;
    };

template <class T>
    struct iterator_traits <T*>{
        typedef T                                  value_type;
        typedef T*                                 pointer;
        typedef T&                                 reference;
        typedef typename std::ptrdiff_t                     difference_type;
        typedef typename ft::random_access_iterator_tag     iterator_category;
    };

template <class T>
    struct iterator_traits <const T*>{
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        typedef typename std::ptrdiff_t                     difference_type;
        typedef typename ft::random_access_iterator_tag     iterator_category;
    };

	template< class InputIt >
	typename std::size_t distance( InputIt first, InputIt last ){
		std::size_t result = 0;
		while (first != last){
			first++;
			result++;
		}
		return (result);
	}

}
#endif