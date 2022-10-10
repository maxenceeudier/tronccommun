/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:42 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/10 18:50:56 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vector/basic_function.hpp"
#include "../srcs/vector/capacity.hpp"
#include "../srcs/vector/iterators.hpp"
#include "../srcs/vector/modifiers.hpp"
#include "../srcs/vector/access_elements.hpp"
#include "../srcs/vector/operators.hpp"
#include "../srcs/vector/vector.hpp"
#include <iostream>
#include <vector>

int test_vector()
{
    ft::vector<int> test1;

    test1.push_back(2);
    test1.push_back(6);
    std::cout << test1;
    std::cout << test1.capacity() << std::endl;
    test1.pop_back();
    std::cout << test1;
    std::cout << test1.capacity() << std::endl;


    ft::vector<int> test2(5, 100);
    std::cout << test2;
    std::cout << test2.capacity() << std::endl;
    test2.push_back(30);
    std::cout << test2;
    std::cout << test2.capacity() << std::endl;
    
    ft::vector<int> test3( test2.begin(), test2.end());
    std::cout << test3;

    ft::vector<int> test4(test1);
    std::cout << test4;

    ft::vector<int> test5;
    test5 = test3;
    std::cout << test5 << test5.capacity() << "\n";
    test5.push_back(10);
    std::cout << test5 << test5.capacity() << "\n";

    ft::vector<int> test6(5, 3);
    test6.push_back(4);
    test6.push_back(4);
    test6.push_back(4);
    test5.insert(test5.begin() + 4, test6.begin() + 3, test6.end());
    std::cout << test5 << test5.capacity() << "\n";


    ft::vector<int> test7(5, 8);
    std::cout << test7;
    ft::vector<int> test8(5, 3);
    test8.push_back(2);
    test7.insert(test7.begin() + 2, test8.begin(), test8.end());
    std::cout << test7 <<  test7.capacity() << std::endl;
    test7.insert(test7.begin() + 4, 3, 100);
    std::cout << test7;
    ft::vector<int>::iterator test7It = test7.erase(test7.begin() + 2, test7.end() - 3);
    std::cout << test7;
    std::cout << *test7It << std::endl;
    test7.resize(3);
    test7.resize(10);
    std::cout << test7;
    std::cout << test7.capacity() << std::endl;
    test7.insert(test7.begin() + 3, 13, 999);
    std::cout << test7;
    std::cout << test7.capacity() << std::endl;

 
    std::cout << test5 << test5.capacity() << "\n";
    test5.insert(test5.end(), test5.rbegin(), test5.rend());
    std::cout << test5 << test5.capacity() << "\n";
    std::cout << test5.max_size() << std::endl;

    ft::vector<int> test9(10, 1);
    ft::vector<int> test10(10, 0);
    std::cout << "test9 : " << test9;
    std::cout << "test10 : " << test10;
    test9.swap(test10);
    std::cout << "test9 : " << test9;
    std::cout << "test10 : " << test10;
    return (0);
}