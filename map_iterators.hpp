#ifndef _MAP_ITERATORS_HPP
#define _MAP_ITERATORS_HPP

namespace ft{

	template < typename T >
	class map_iterator : public iterator< ft::bidirectional_iterator_tag, T >
	{
		public :

			typedef typename iterator<ft::bidirectional_iterator_tag, T>::pointer				pointer;
            typedef typename iterator<ft::bidirectional_iterator_tag, T>::reference     		reference;
            typedef typename iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            typedef typename iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            typedef typename iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
			typedef typename iterator_traits<bidirectional_iterator<T> >::iterator_type			iterator_type;

		private :

			pointer _it;

	};

	template < typename Iter >
	class map_reverse_iterator
	{
		public :
		
			typedef Iter														iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category		iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type				value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type			difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer					pointer;
			typedef typename ft::iterator_traits<Iter>::reference				reference;

	};



}



#endif