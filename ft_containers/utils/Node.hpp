/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:53:33 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/09/15 19:17:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP
#include "Pair.hpp"

namespace ft
{
    enum    e_color
    {
        BLACK,
        RED,
        DOUBLE_BLACK
    };
    
    template<typename Tkey, typename Tvalue>
    class Node
    {
        public:
            Node(void){};
            Node(ft::pair<Tkey, Tvalue> &pair) : pair(pair), color(RED), parent(NULL), left(NULL), right(NULL){};
            Node(Node const &node)
            {
                *this = node;
                return ;
            };
            ~Node(void){};
            Node &operator=(Node const &node)
            {
                pair = node.pair;
                color = node.color;
                parent = node.parent;
                left = node.left;
                right = node.right;
                return (*this);
            };

            ft::pair<Tkey, Tvalue>  pair;
            int                     color;
            Node                    *parent;
            Node                    *left;
            Node                    *right;
    };

    template<typename Tkey, typename Tvalue>
    std::ostream	&operator<<(std::ostream &o, Node<Tkey, Tvalue> *node)
    {
        std::cout << "key = " << node->pair.first \
        << ", value = " << node->pair.second << " " << std::endl;
        std::cout << "color : ";
        if (node->color == BLACK)
            std::cout << "black";
        if (node->color == DOUBLE_BLACK)
            std::cout << "double black";
        if (node->color == RED)
            std::cout << "red";
        std::cout << std::endl;
        return (o);
    }
    
}

#endif