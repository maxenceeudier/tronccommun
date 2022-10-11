/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_std.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:50:45 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/11 19:37:19 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "test.h"

int test_utils()
{
    /*----------is_integral-----------------*/
    std::cout << GREEN;
    std::cout << " --------------- " << std::endl;
    std::cout << "| is_integral : |" << std::endl;
    std::cout << " --------------- " << std::endl;
    std::cout << RESET;
    std::cout << GREEN << "int:                 " << RESET << std::is_integral<int>::value << std::endl;
    std::cout << GREEN << "float :              " << RESET  << std::is_integral<float>::value << std::endl;
    std::cout << GREEN << "char:                " << RESET  << std::is_integral<char>::value << std::endl;
    std::cout << GREEN << "char32_t:            " << RESET  << std::is_integral<char32_t>::value << std::endl;
    std::cout << GREEN << "unsigned short int : " << RESET  << std::is_integral<unsigned short int>::value << std::endl;
    std::cout << std::endl << std::endl;

    /*-----------pair-----------------------*/
    std::cout << GREEN;
    std::cout << " --------------- " << std::endl;
    std::cout << "|     Pair :    |" << std::endl;
    std::cout << " --------------- " << std::endl;
    std::cout << RESET;
    std::string                       str = "hello";
    std::pair<std::string, int>             pr1;
    std::pair<const int, const float>       pr2(1, 3.33);
    pr1 = std::make_pair(str, 3);
    std::pair<std::string, unsigned int>    pr3(pr1);
    std::pair<std::string, int>             pr4;
    pr4 = pr1;

    std::cout << GREEN << "str :                    " << RESET << str << std::endl;
    std::cout << GREEN << "pr1 = make_pair(str, 3):\n" << RESET;
    std::cout << "      -key:       " << pr1.first  << std::endl;
    std::cout << "      -value:     " << pr1.second  << std::endl;
    std::cout << GREEN << "pr2(1, 3.33):\n" << RESET;
    std::cout << "      -key:       " << pr2.first  << std::endl;
    std::cout << "      -value:     " << pr2.second  << std::endl;
    std::cout << GREEN << "pr3(pr1):\n" << RESET;
    std::cout << "      -key:       " << pr3.first  << std::endl;
    std::cout << "      -value:     " << pr3.second  << std::endl;
    std::cout << GREEN << "pr4 = pr2:\n" << RESET;
    std::cout << "      -key:       " << pr4.first  << std::endl;
    std::cout << "      -value:     " << pr4.second  << std::endl;
    std::cout << std::endl << std::endl;

    /*-------------equal------------------*/
    std::cout << GREEN;
    std::cout << " --------------- " << std::endl;
    std::cout << "|     equal :    |" << std::endl;
    std::cout << " --------------- " << std::endl;
    std::cout << RESET;
    std::vector<int>     vec1(10, 0);
    std::vector<int>     vec2(vec1);
    std::vector<int>     vec3(10, 1);

    std::cout << GREEN << "vec1(10, 0), vec2(vec1), vec3(10, 1):\n" << RESET;
    std::cout << GREEN << "equal(vec1.begin(), vec1.end(), vec2.begin()):    " << RESET << std::equal(vec1.begin(), vec1.end(), vec2.begin());
    std::cout << std::endl;
    std::cout << GREEN << "equal(vec1.begin(), vec1.end(), vec3.begin()): " << RESET << std::equal(vec1.begin(), vec1.end(), vec3.begin());
    std::cout << std::endl;
    std::cout << std::endl << std::endl;

    /*--------------distance--------------*/
    std::cout << GREEN;
    std::cout << " --------------- " << std::endl;
    std::cout << "|   distance :  |" << std::endl;
    std::cout << " --------------- " << std::endl;
    std::cout << RESET;
    std::vector<int> arr(5, 1);
    std::cout << "vector<int> arr(5, 1):\n";
    std::cout << "      distance -> (arr.begin(), arr.end()):   ";
    std::cout << GREEN << std::distance<std::vector<int>::iterator>(arr.begin(), arr.end()) << RESET;
    
    return (0);
}

int main()
{
    test_utils();
    return (0);
}