/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_RBT.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:00:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 16:09:20 by maxenceeudi      ###   ########.fr       */
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
    std::cout << " --------------- " << std::endl;
    std::cout << "|   node :      |" << std::endl;
    std::cout << " --------------- " << std::endl;
    const std::string                   st("test");
    ft::pair<std::string, int>          pair(st, 3);
    Node<ft::pair<std::string, int> >   *node = new Node<ft::pair<std::string, int> >(pair);
    const std::string                   st2("test2");
    ft::pair<std::string, int>          pair2(st2, 5);
    Node<ft::pair<std::string, int> >   *node2 = new Node<ft::pair<std::string, int> >(pair2);

    std::cout << "node(pair(\"test\", 3):\n";
    std::cout << node << std::endl;
    node2->color = BLACK;
    std::cout << "node2(pair(\"test2\", 5)), node2->color = BLACK:\n";
    std::cout << node2 << std::endl;
    delete node;
    delete node2;
    std::cout << std::endl;
    
    /*----------------RBTree-----------------*/
    std::cout << " --------------- " << std::endl;
    std::cout << "|   RBTree :    |" << std::endl;
    std::cout << " --------------- " << std::endl;
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
    std::cout << "tree; inertValue 4, 10, -6, ..., -9:\n";
    tree.printTree();
    std::cout << std::endl;

    tree.deleteValue(-10);
    std::cout << "tree deleteValue(-10):\n";
    tree.printTree();
    std::cout << std::endl;

    std::cout << "cpy(tree); :\n";
    ft::RBTree<int> cpy(tree);
    cpy.printTree();
    std::cout << std::endl;

    {
        ft::RBTree<int> clone;
        clone = cpy;
        std::cout << "clone = cpy: \n";
        clone.printTree();
        std::cout << std::endl;
    }
    
    std::cout << "cpy: \n";
    cpy.printTree();
    std::cout << std::endl;
    
    std::cout << "tree.deleteValue(4):\n";
    tree.deleteValue(4);
    tree.printTree();
    std::cout << std::endl;
}

int main()
{
    testRBT();
    return (0);
}