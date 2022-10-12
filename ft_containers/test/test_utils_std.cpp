/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_std.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:50:45 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 16:09:38 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

int test_utils()
{
    /*----------is_integral-----------------*/
    
    std::cout << " --------------- " << std::endl;
    std::cout << "| is_integral : |" << std::endl;
    std::cout << " --------------- " << std::endl;
    
    std::cout << "int:                 " << std::is_integral<int>::value << std::endl;
    std::cout << "float :              "  << std::is_integral<float>::value << std::endl;
    std::cout << "char:                "  << std::is_integral<char>::value << std::endl;
    std::cout << "char32_t:            "  << std::is_integral<char32_t>::value << std::endl;
    std::cout << "unsigned short int : "  << std::is_integral<unsigned short int>::value << std::endl;
    std::cout << std::endl << std::endl;

    /*-----------pair-----------------------*/
    
    std::cout << " --------------- " << std::endl;
    std::cout << "|     Pair :    |" << std::endl;
    std::cout << " --------------- " << std::endl;
    
    std::string                       str = "hello";
    std::pair<std::string, int>             pr1;
    std::pair<const int, const float>       pr2(1, 3.33);
    pr1 = std::make_pair(str, 3);
    std::pair<std::string, unsigned int>    pr3(pr1);
    std::pair<std::string, int>             pr4;
    pr4 = pr1;

    std::cout << "str :                    " << str << std::endl;
    std::cout << "pr1 = make_pair(str, 3):\n";
    std::cout << "      -key:       " << pr1.first  << std::endl;
    std::cout << "      -value:     " << pr1.second  << std::endl;
    std::cout << "pr2(1, 3.33):\n";
    std::cout << "      -key:       " << pr2.first  << std::endl;
    std::cout << "      -value:     " << pr2.second  << std::endl;
    std::cout << "pr3(pr1):\n";
    std::cout << "      -key:       " << pr3.first  << std::endl;
    std::cout << "      -value:     " << pr3.second  << std::endl;
    std::cout << "pr4 = pr2:\n";
    std::cout << "      -key:       " << pr4.first  << std::endl;
    std::cout << "      -value:     " << pr4.second  << std::endl;
    std::cout << std::endl << std::endl;

    /*-------------equal------------------*/
    
    std::cout << " --------------- " << std::endl;
    std::cout << "|     equal :    |" << std::endl;
    std::cout << " --------------- " << std::endl;
    
    std::vector<int>     vec1(10, 0);
    std::vector<int>     vec2(vec1);
    std::vector<int>     vec3(10, 1);

    std::cout << "vec1(10, 0), vec2(vec1), vec3(10, 1):\n";
    std::cout << "equal(vec1.begin(), vec1.end(), vec2.begin()):    " << std::equal(vec1.begin(), vec1.end(), vec2.begin());
    std::cout << std::endl;
    std::cout << "equal(vec1.begin(), vec1.end(), vec3.begin()): " << std::equal(vec1.begin(), vec1.end(), vec3.begin());
    std::cout << std::endl;
    std::cout << std::endl << std::endl;

    /*--------------distance--------------*/
    
    std::cout << " --------------- " << std::endl;
    std::cout << "|   distance :  |" << std::endl;
    std::cout << " --------------- " << std::endl;
    
    std::vector<int> arr(5, 1);
    std::cout << "vector<int> arr(5, 1):\n";
    std::cout << "      distance -> (arr.begin(), arr.end()):   ";
    std::cout << std::distance<std::vector<int>::iterator>(arr.begin(), arr.end());
    
    return (0);
}

int main()
{
    test_utils();
    return (0);
}