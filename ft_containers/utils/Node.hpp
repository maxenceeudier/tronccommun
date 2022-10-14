/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:53:33 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/14 10:52:05 by meudier          ###   ########.fr       */
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
        o << node->data << std::endl;
        o << "color : ";
        if (node->color == BLACK)
            o << "black";
        if (node->color == DOUBLE_BLACK)
            o << "double black";
        if (node->color == RED)
            o << "red";
        o << std::endl;
        return (o);
    }


    
}

#endif