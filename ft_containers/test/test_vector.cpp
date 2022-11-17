/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:42 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/17 12:20:05 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vector/vector.h"

int test_vector()
{
    std::cout << " -------------------------------- \n";
    std::cout << "| test push and pop and capacity |\n";
    std::cout << "| default constructor            |\n";
    std::cout << " -------------------------------- \n" << std::endl;
    ft::vector<int> test1;
    std::cout << "test1():\n";
    std::cout << "      -test1:            " << test1;
    std::cout << "      -test1.capacity:   " << test1.capacity();
    std::cout << std::endl << std::endl;
    test1.push_back(2);
    test1.push_back(6);
    std::cout << "test1.push_back() 2 and 6:\n";
    std::cout << "      -test1:            " << test1;
    std::cout << "      -test1.capacity:   " << test1.capacity();
    std::cout << std::endl << std::endl;
    test1.pop_back();
    std::cout << "test1.pop():\n";
    std::cout << "      -test1:            " << test1;
    std::cout << "      -test1.capacity:   " << test1.capacity();
    std::cout << std::endl << std::endl;
    test1.push_back(10);
    test1.push_back(-67);
    test1.push_back(3);
    std::cout << "test1.push_back() 10, -67, 3:\n";
    std::cout << "      -test1:            " << test1;
    std::cout << "      -test1.capacity:   " << test1.capacity();
    std::cout << std::endl << std::endl;;
    while (test1.size())
        test1.pop_back();
    std::cout << "size x test1.pop():\n";
    std::cout << "      -test1:            " << test1;
    std::cout << "      -test1.capacity:   " << test1.capacity();
    std::cout << std::endl << std::endl;


    std::cout << " ----------------------------- \n";
    std::cout << "| test push, pop and capacity |\n";
    std::cout << "| constructor(size_t, value)  |\n";
    std::cout << " ----------------------------- \n" << std::endl;
    ft::vector<int> test2(5, 100);
    std::cout << "test2(5, 100):\n";
    std::cout << "      -test2:             " << test2;
    std::cout << "      -test2.capacity:    " << test2.capacity();
    std::cout << std::endl << std::endl;
    test2.push_back(1);
    test2.push_back(2);
    test2.push_back(3);
    std::cout << "test2.push_back 1, 2, 3:\n";
    std::cout << "      -test2:             " << test2;
    std::cout << "      -test2.capacity:    " << test2.capacity();
    std::cout << std::endl << std::endl;
    


    std::cout << " -------------------------- \n";
    std::cout << "| constructor(first, last) |\n";
    std::cout << "| constructor(cpy)         |\n";
    std::cout << "| assignement operator     |\n";
    std::cout << " -------------------------- \n" << std::endl;
    ft::vector<int> test3(test2.begin(), test2.end());
    std::cout << "test3(test2.begin(), test2.end()):\n";
    std::cout << "      -test3:     " << test3;
    std::cout << std::endl;

    ft::vector<int> test4(test3);
    std::cout << "test4(test3):\n";
    std::cout << "      -test4:         " << test4;
    std::cout << std::endl;
    
    ft::vector<int> test5;
    test5 = test3;
    std::cout << "test5 = test4:\n";
    std::cout << "      -test5:         " << test5;
    std::cout << "      -test5capacity: " << test5.capacity();
    std::cout << std::endl << std::endl;
    test5.pop_back();
    test5.push_back(9);
    test5.push_back(10);
    test5.push_back(11);
    std::cout << "test5.pop_back(), test5.push_back() 9, 10, 11:\n";
    std::cout << "      -test5:         " << test5;
    std::cout << "      -test5capacity: " << test5.capacity();
    std::cout << std::endl << std::endl;

    std::cout << " -------------------------- \n";
    std::cout << "| insert(pos, first, last) |\n";
    std::cout << "| insert(pos, value)       |\n";
    std::cout << "| insert(pos, n, value)    |\n";
    std::cout << "| iterators                |\n";
    std::cout << " -------------------------- \n" << std::endl;
    ft::vector<int> test6(5, 6);
    test5.insert(test5.begin() + 4, test6.begin() + 3, test6.end());
    std::cout << "test6(5, 6); test5.insert(test5.begin() + 4, test6.begin() + 3, test6.end()):\n";
    std::cout << "      -test5:         " << test5;
    std::cout << "      -test5capacity: " << test5.capacity();
    std::cout << std::endl << std::endl;

    ft::vector<int> test7(5, 8);
    std::cout << "test7(5, 8):\n";
    std::cout << "      -test7:         " << test7;
    ft::vector<int> test8(5, 3);
    test8.push_back(2);
    std::cout << "test8(5, 3), test8.push_back(2):\n";
    std::cout << "      -test8:         " << test8;
    std::cout << std::endl;
    
    test7.insert(test7.begin() + 2, test8.begin(), test8.end() - 2);
    std::cout << "test7.insert(test7.begin() + 2, test8.begin(), test8.end() - 2):\n";
    std::cout << "      -test7:             " << test7;
    std::cout << "      -test7.capacity:    " << test7.capacity();
    std::cout << std::endl << std::endl;

    test7.insert(test7.begin() + 3, 999);
    std::cout << "test7.insert(test7.begin() + 3, 999):\n";
    std::cout << "      -test7:             " << test7;
    std::cout << "      -test7.capacity:    " << test7.capacity();
    std::cout << std::endl << std::endl;

    test8.insert(test8.begin() + 4, 3, 100);
    std::cout << "test8.insert(test8.begin() + 2, 3, 100):\n";
    std::cout << "      -test8:             " << test8;
    std::cout << "      -test8.capacity:    " << test8.capacity();
    std::cout << std::endl << std::endl;

    
    std::cout << test5 << test5.capacity() << "\n";
    std::cout << "test5:\n";
    std::cout << "      -test5:             " << test5;
    std::cout << "      -test5.capacity:    " << test5.capacity();
    std::cout << std::endl << std::endl;
    
    test5.insert(test5.end() - 2, test5.rbegin() , test5.rend() - 1);
    std::cout << "test5.insert(test5.end() - 2, test5.rbegin(), test5.rend() - 1):\n";
    std::cout << "      -test5:             " << test5;
    std::cout << "      -test5.capacity:    " << test5.capacity();
    std::cout << std::endl << std::endl;
    

    std::cout << " -------------------------- \n";
    std::cout << "| max_size                 |\n";
    std::cout << "| erase                    |\n";
    std::cout << "| resize                   |\n";
    std::cout << " -------------------------- \n" << std::endl;
    
    std::cout << "test5.max_size():\n";
    std::cout << "      -test5.max_size():  " << test5.max_size();
    std::cout << std::endl << std::endl;

    std::cout << "test7; test7.erase(test7.begin() + 2, test7.end() - 3) and rslt:\n";
    std::cout << "      -test7:     " << test7;
    ft::vector<int>::iterator test7It = test7.erase(test7.begin() + 2, test7.end() - 3);
    std::cout << "      -test7:     " << test7;
    std::cout << "      -rslt:      " << *test7It;
    std::cout << std::endl << std::endl;

    std::cout << "test7.resize(3); test7.resize(10):\n";
    test7.resize(3);
    test7.resize(10);
    std::cout << "      -test7:             " << test7;
    std::cout << "      -test7.capacity:    " << test7.capacity();
    std::cout << std::endl << std::endl;

    
    std::cout << " ----------------- \n";
    std::cout << "| swap            |\n";
    std::cout << "| operator        |\n";
    std::cout << " ----------------- \n" << std::endl;
    ft::vector<int> test9(10, 1);
    ft::vector<int> test10(10, 0);
    std::cout << "      test9 : " << test9;
    std::cout << "      test10 : " << test10;
    test9.swap(test10);
    std::cout << "swap:\n";
    std::cout << "      test9 : " << test9;
    std::cout << "      test10 : " << test10;
    std::cout << std::endl << std::endl;


    std::cout << "operators:\n";
    std::cout << "test9 < test10:   " << (test9 < test10) << std::endl;
    std::cout << "test9 > test10:   " << (test9 > test10) << std::endl;
    std::cout << "test9 <= test10:  " << (test9 <= test10) << std::endl;
    std::cout << "test9 >= test10:  " << (test9 >= test10) << std::endl;
    std::cout << "test9 == test10:  " << (test9 == test10) << std::endl;
    std::cout << "test9 != test10:  " << (test9 != test10) << std::endl;
    std::cout << std::endl << std::endl;

    ft::vector<int>    test11(test10);
    test11.resize(test11.size() + 1);
    std::cout << "test11(test10); test11.resize(test11.size() + 1):\n";
    std::cout << "test11 < test10:  " << (test11 < test10) << std::endl;
    std::cout << "test11 > test10:  " << (test11 > test10) << std::endl;
    std::cout << "test11 <= test10: " << (test11 <= test10) << std::endl;
    std::cout << "test11 >= test10: " << (test11 >= test10) << std::endl;
    std::cout << "test11 == test10: " << (test11 == test10) << std::endl;
    std::cout << "test11 != test10: " << (test11 != test10) << std::endl;
    std::cout << test11;
    std::cout << test10;


    for (ft::vector<int>::iterator it = test10.begin(); it != test10.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    return (0);
}

int main ()
{
    test_vector();
    return (0);
}
