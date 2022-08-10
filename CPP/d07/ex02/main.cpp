/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:47:19 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 13:14:06 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int main()
{
    try
    {
        ::Array<int>(-1);
    }
    catch(const std::string & e)
    {
        std::cerr << e << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        ::Array<int> array(5);
        unsigned int i = 0;
        while (i < array.size())
            std::cout << array[i++];
        std::cout << std::endl;
        i = 0;
        while (i < array.size())
        {
            array[i] = i + 1;
            i++;
        }
        i = 0;
        while (i < array.size())
            std::cout << array[i++];
    }
    catch(const std::string & e)
    {
        std::cerr << e << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        ::Array<int> array(5);
        unsigned int i = 0;
        while (i < array.size())
        {
            array[i] = i + 1;
            i++;
        }
        ::Array<int> cpy(array);
        i = 0;
        while (i < cpy.size())
            std::cout << cpy[i++];
    }
    catch(const std::string & e)
    {
        std::cerr << e << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        ::Array<int> array(5);
        ::Array<int> cpy;
        unsigned int i = 0;
        while (i < array.size())
        {
            array[i] = i + 1;
            i++;
        }
        cpy = array;
        i = 0;
        while (i < cpy.size())
            std::cout << cpy[i++];
    }
    catch(const std::string & e)
    {
        std::cerr << e << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        ::Array<int> array(5);
        array[5] = 2;
    }
    catch(const std::string & e)
    {
        std::cerr << e << '\n';
    }
    
    return (0);
}