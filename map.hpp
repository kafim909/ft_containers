#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <iostream>
# include "colors.hpp"
# include "map_iterators.hpp"
# include "utils.hpp"

namespace ft
{
	template < typename T, typename U >
	struct node 
	{
		typedef T	key_type;
		typedef U	value_type;


		node();
		explicit node(key_type& key, value_type& value) : key(key), value(value), right(NULL), left(NULL) {}
		explicit node(const node& copy) : key(copy.key), value(copy.value), right(copy.right), left(copy.left) {}

		key_type	key;
		value_type	value;
		
		protected :
		
			struct node *left;
			struct node *right;

		bool operator<(node &other) {return (key < other.key);}
	};

	template < class Key, Class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		
		public :

			typedef	Key												key_type;
			typedef T												mapped_type;
			typedef pair<const key_type, mapped_type>				value_type;
			typedef	Compare											key_compare;

			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename map_iterator<value_type>				iterator;
			typedef typename map_iterator<const value_type>			const_iterator;
			typedef typename map_reverse_iterator<iterator>			reverse_iterator;
			typedef typename map_reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef typename

	};
}


#endif