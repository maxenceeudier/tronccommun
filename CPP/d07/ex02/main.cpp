/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:47:19 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 13:39:03 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int main()
{
    try
    {
        ::Array<int>(-1);
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
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
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
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
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
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
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        ::Array<int> array(5);
        array[5] = 2;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}

/*#include <iostream>
#include "array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}*/