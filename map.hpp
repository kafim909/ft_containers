#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <iostream>
# include "colors.hpp"
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
		struct node *left;
		struct node *right;

		bool operator<(node &other) {return (key < other.key);}
	};

	template < typename T, typename U >
	class map : public node < T , U >
	{
		public :
		
			typedef typename node::key_type		key_type;
			typedef typename node::value_type	vale_type;

			map() : root(NULL);



			node addNode(key_type& key, value_type& value)
			{
				node newNode(key, value);
				if (!root)
					root = &newNode;
				else
				{
					node tmp(*root);
					while (1)
					{
						if (newNode < tmp && tmp->left)
						{
							tmp = tmp->left;
							if (!tmp->left)
							{
								tmp->left = &newNode;
								break ;
							}
						}	
						else if (!(newNode < tmp) && tmp->right)
						{
							tmp = tmp->right;
							if (tmp->right)
							{
								tmp->right = &newNode;
								break ;
							}
						}
					}
				}
				return (newNode);	
			}


		private :

			node *root;
	};
}

#endif