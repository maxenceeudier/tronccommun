/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_RBT.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:00:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/11 11:11:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include "../utils/equal.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/Pair.hpp"
#include "../utils/swap.hpp"
#include "../utils/Node.hpp"
#include "../utils/swap.hpp"
#include "../utils/RBTree_impl.hpp"
#include "../utils/distance.hpp"

using namespace ft;

void testRBT()
{
    /*----------------node-----------------*/
    const std::string     st("test");
    ft::pair<std::string, int>    pair(st, 3);
    Node<ft::pair<std::string, int> >   *node = new Node<ft::pair<std::string, int> >(pair);
    const std::string     st2("test2");
    ft::pair<std::string, int>    pair2(st2, 5);
    Node<ft::pair<std::string, int> >   *node2 = new Node<ft::pair<std::string, int> >(pair2);

    std::cout << node;
    node2->color = BLACK;
    std::cout << node2;
    ft::swap(node->color, node2->color);
    std::cout << node;
    std::cout << node2;
    delete node;
    delete node2;
    std::cout << std::endl;
    
    /*----------------RBTree-----------------*/
    ft::RBTree<int> tree;
    tree.insertValue(4);
    tree.insertValue(10);
    tree.insertValue(-6);
    tree.insertValue(5);
    tree.insertValue(64);
    tree.insertValue(-10);
    tree.insertValue(35);
    tree.insertValue(264);
    tree.insertValue(-9);
    
    tree.printTree();
    tree.deleteValue(-10);
    tree.printTree();

    std::cout << "cpy :\n";
    ft::RBTree<int> cpy(tree);
    cpy.printTree();
    {
        ft::RBTree<int> clone;
        clone = cpy;
        std::cout << "clone: \n";
        clone.printTree();
    }
    std::cout << "cpy: \n";
    cpy.printTree();
    tree.deleteValue(4);
    tree.printTree();
    std::cout << std::endl;
}

int main()
{
    testRBT();
    return (0);
}