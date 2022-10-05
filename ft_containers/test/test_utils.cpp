/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:12:52 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/05 14:53:09 by maxenceeudi      ###   ########.fr       */
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
#include <vector>

using namespace ft;

int test_utils()
{

    /*----------is_integral-----------------*/
    std::cout << "is_integral :" << std::endl;
    std::cout << "int: " << ft::is_integral<int>::value << std::endl;
    std::cout << "float :" << ft::is_integral<float>::value << std::endl;
    std::cout << "char: " << ft::is_integral<char>::value << std::endl;
    std::cout << "char32_t : " << ft::is_integral<char32_t>::value << std::endl;
    std::cout << "unsigned short int : " << ft::is_integral<unsigned short int>::value << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "is_integral :" << std::endl;
    std::cout << "int: " << std::is_integral<int>::value << std::endl;
    std::cout << "float :" << std::is_integral<float>::value << std::endl;
    std::cout << "char: " << std::is_integral<char>::value << std::endl;
    std::cout << "char32_t : " << std::is_integral<char32_t>::value << std::endl;
    std::cout << "unsigned short int : " << std::is_integral<unsigned short int>::value << std::endl;
    std::cout << std::endl << std::endl;

    /*-----------pair-----------------------*/
    std::cout << "Pair :"       << std::endl;
    const std::string                   str = "hello";
    ft::pair<std::string, int>          pri;
    ft::pair<int, float>                prif(1, 3.33);
    pri = ft::make_pair(str, -1);
    ft::pair<std::string, unsigned int> prui(pri);
    ft::pair<std::string, int>          pri2;
    pri2 = pri;
    
    std::cout << "make_pair : " << pri;
    std::cout << "cpy : "       << prui;
    std::cout << "args : "      << prif;
    std::cout << "== : "        << (pri2 == pri) << std::endl;
    std::cout << "!= : "        << (pri2 != pri) << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Pair :"       << std::endl;
    std::pair<std::string, int>          prii2;
    std::pair<const int, const float>                prif2(1, 3.33);
    prii2 = std::make_pair(str, -1);
    std::pair<std::string, unsigned int> prui2(prii2);
    std::pair<std::string, int>          pri4;
    pri4 = prii2;
    
    std::cout << "make_pair : " << "key = " << prii2.first;
    std::cout << ", value = " << prii2.second << std::endl;
    std::cout << "cpy : " << "key = " << prui2.first;
    std::cout << ", value = " << prui2.second << std::endl;
    std::cout << "args : " << "key = " << prif2.first;
    std::cout << ", value = " << prif2.second << std::endl;
    std::cout << std::endl << std::endl;

    /*-------------equal------------------*/
    std::vector<int>     vec1(10, 0);
    std::vector<int>     vec2(vec1);
    std::vector<int>     vec3(10, 1);

    std::cout << "equal :" << std::endl;
    std::cout << "eq true: " << ft::equal(vec1.begin(), vec1.end(), vec2.begin());
    std::cout << std::endl;
    std::cout << "eq flase: " << ft::equal(vec1.begin(), vec1.end(), vec3.begin());
    std::cout << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "equal :" << std::endl;
    std::cout << "eq true: " << std::equal(vec1.begin(), vec1.end(), vec2.begin());
    std::cout << std::endl;
    std::cout << "eq flase: " << std::equal(vec1.begin(), vec1.end(), vec3.begin());
    std::cout << std::endl;
    std::cout << std::endl << std::endl;


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

    /*--------------distance--------------*/
    
    std::vector<int> arr(5, 1);
    std::cout << ft::distance<std::vector<int>::iterator>(arr.begin(), arr.end());
    
    return (0);
}
