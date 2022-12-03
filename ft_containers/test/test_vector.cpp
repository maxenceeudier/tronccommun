/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:42 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/02 21:34:02 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/include.h"
#include <ctime>

int test_vector_std()
{

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         VECTOR           */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    std::time_t t0 = std::time(NULL);
    std::cout << std::asctime(std::localtime(&t0));
    
    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*       BASICS FUNCT       */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    ft::vector<int> vec;
    std::cout << "\n\nvec():\n";
    std::cout << vec << std::endl;
    vec.push_back(10);
    vec.push_back(-67);
    vec.push_back(3);
    std::cout << "\npush some value\n";
    std::cout << vec << std::endl;

    ft::vector<int> vec2;
    
    {
        ft::vector<int> vec3(vec);
        vec2 = vec3;
    }
    
    std::cout << "cpy() and = construct\n";
    std::cout << vec2;

    ft::vector<int> vec3(10,1);
    std::cout << "\ncpy(size, value)\n";
    std::cout << vec3;

    ft::vector<int> vec4(vec3.begin(), vec3.end());
    std::cout << "\ncpy(first, last)\n";
    std::cout << vec4 << std::endl;

    vec4.assign(3, 4);
    std::cout << "\nassign(size, val)\n";
    std::cout << vec4 << std::endl;


    vec4.assign(vec.begin(), vec.begin() + 2);
    std::cout << "\nassign(first, last)\n";
    std::cout << vec4 << std::endl;


    int * val = vec.get_allocator().allocate(1);
    vec.get_allocator().construct(val, 3);
    std::cout << "\ntest get alloc:\n" << *val << std::endl;
    vec.get_allocator().destroy(val);
    vec.get_allocator().deallocate(val, 1);
    

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*       ACCESS ELEMTS      */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    const ft::vector<int> vecConst = vec;
    std::cout << "\nat():\n";
    std::cout << vec.at(2) << std::endl;
    
    std::cout << "\nat() const :\n";
    std::cout << vecConst.at(2) << std::endl;

    std::cout << "\nfront():\n";
    std::cout << vec.front() << std::endl;
    
    std::cout << "\nfront() const :\n";
    std::cout << vecConst.front() << std::endl;

    std::cout << "\nback():\n";
    std::cout << vec.back() << std::endl;
    
    std::cout << "\nback() const :\n";
    std::cout << vecConst.back() << std::endl;

    ft::vector<int> myvector (5);
    int* p = myvector.data();
    *p = 10;
    ++p;
    *p = 20;
    p[2] = 100;

    std::cout << "\ntest data(): myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    std::cout << "\n\ntest vec[1] = 2\n";
    std::cout << vec;
    vec[1] = 2;
    std::cout << vec;
    std::cout << std::endl << std::endl;

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         CAPACITY         */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    std::cout << "\n\ntest empty()\n\n";
    std::cout << vec4 << " empty() : " << vec4.empty() << "\nsize() : " << vec4.size() << "\ncapacity() : " << vec4.capacity();
    vec4.insert(vec4.end(), vec.begin(), vec.end());
    vec4.insert(vec4.end(), vec.begin(), vec.end());
    vec4.insert(vec4.end(), vec4.begin(), vec4.end());
    std::cout << "\n\nvec4.insetr some value\n" <<  vec4 << " empty() : " <<  vec4.empty() << "\nsize() : " << vec4.size() << "\ncapacity() : " << vec4.capacity();
    vec4.clear();
    std::cout << "\n\nvec4.clear()\n" <<  vec4 << " \nempty() : " <<  vec4.empty() << "\nsize() : " << vec4.size() << "\ncapacity() : " << vec4.capacity();

    std::cout << "\nmax_size() : " << vec.max_size();
    
    std::cout << std::endl << std::endl;

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*        ITERATORS         */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    
    const ft::vector<int> vecConst2 = vec;
    
    std::cout << "\n\nbegin(), end()\n[ ";
    for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << " ]";

     std::cout << "\n\nrbegin(), rend()\n[ ";
    for (ft::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << " ]";

     std::cout << "\n\ncbegin(), cend()\n[ ";
    for (ft::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << " ]";

    std::cout << "\n\ncrbegin(), crend()\n[ ";
    for (ft::vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << " ]\n\n";


    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*        OPERATORS         */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    ft::vector<std::string> test9(10, "yo");
    ft::vector<std::string> test10(10, "ya");
    
    std::cout << "operators:\n";
    std::cout << "test9 < test10:   " << (test9 < test10) << std::endl;
    std::cout << "test9 > test10:   " << (test9 > test10) << std::endl;
    std::cout << "test9 <= test10:  " << (test9 <= test10) << std::endl;
    std::cout << "test9 >= test10:  " << (test9 >= test10) << std::endl;
    std::cout << "test9 == test10:  " << (test9 == test10) << std::endl;
    std::cout << "test9 != test10:  " << (test9 != test10) << std::endl;
    std::cout << std::endl << std::endl;

    ft::vector<std::string>    test11(test10);
    test11.resize(test11.size() + 5);
    std::cout << "test11(test10); test11.resize(test11.size() + 1):\n";
    std::cout << "test11 < test10:  " << (test11 < test10) << std::endl;
    std::cout << "test11 > test10:  " << (test11 > test10) << std::endl;
    std::cout << "test11 <= test10: " << (test11 <= test10) << std::endl;
    std::cout << "test11 >= test10: " << (test11 >= test10) << std::endl;
    std::cout << "test11 == test10: " << (test11 == test10) << std::endl;
    std::cout << "test11 != test10: " << (test11 != test10) << std::endl;
    
    std::cout << test11;
    std::cout << test10;
     std::cout << std::endl << std::endl;

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         MODIFIERS        */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    
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
    
    test5.insert(test5.end() - 2, test5.rbegin(), test5.rend() - 1);
    
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
    std::cout << " ----------------- \n" << std::endl;
    ft::vector<int> test12(10, 1);
    ft::vector<int> test13(10, 0);
    std::cout << "      test12 : " << test12;
    std::cout << "      test13 : " << test13;
    test12.swap(test13);
    
    std::cout << "swap:\n";
    std::cout << "      test12 : " << test2;
    std::cout << "      test13 : " << test13;
    std::cout << std::endl << std::endl;

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         perfo            */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;


    ft::vector<long int> perf;
    size_t i = 0;
    while (i < 10000)
    {
        perf.push_back(i++);
    }
    i = 0;
    while (i++ < perf.size())
    {
        ft::vector<long int> temp;
        temp.insert(temp.begin(), perf.begin(), perf.end());
    }
    
    std::time_t t1 = std::time(NULL);
    std::cout << std::asctime(std::localtime(&t1));    
    std::cout << "\n\nthe programme took: " << t1 - t0 << "s\n";
    return (0);
}

int main()
{
    test_vector_std();
    return (0);
}