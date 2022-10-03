/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:53:33 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/03 11:31:11 by maxenceeudi      ###   ########.fr       */
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
    
    template<typename T>
    class Node
    {
        public:
            Node(void){};
            Node(T &data) : data(data), color(RED), parent(NULL), left(NULL), right(NULL){};
            Node(Node const &node)
            {
                *this = node;
                return ;
            };
            ~Node(void){};
            Node &operator=(Node const &node)
            {
                data = node.data;
                color = node.color;
                parent = node.parent;
                left = node.left;
                right = node.right;
                return (*this);
            };

            T       data;
            int     color;
            Node    *parent;
            Node    *left;
            Node    *right;
    };

    template<typename T>
    std::ostream	&operator<<(std::ostream &o, Node<T> *node)
    {
        std::cout << node->data << std::endl;
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