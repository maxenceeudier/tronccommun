/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:33:01 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/11 15:44:50 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span test(5);
        test.addNumber(1);
        test.addNumber(34);
        test.addNumber(5524);
        test.addNumber(-23);
        test.addNumber(-4);
        test.printSpan();
        std::cout << "shortest span: " << test.shortestSpan() << std::endl;
        std::cout << "longest span: " << test.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        Span test(5);
        test.addNumber(1);
        test.addNumber(1);
        test.addNumber(1);
        test.addNumber(1);
        test.addNumber(1);
        test.addNumber(1);
        test.addNumber(1);
        test.printSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        Span test(10);
        std::vector<int> tab1(5, 2);
        std::vector<int> tab2(6, 1);
        test.addNumbers(tab1.begin(), tab1.end());
        test.printSpan();
        test.addNumbers(tab2.begin(), tab2.end());
        test.printSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        Span test(20);
        std::vector<int> tab1(10, 4);
        std::vector<int> tab2(2, 1);
        test.addNumbers(tab1.begin(), tab1.end());
        test.addNumbers(tab2.begin(), tab2.end());
        test.printSpan();
        std::cout << "shortest span: " << test.shortestSpan() << std::endl;
        std::cout << "longest span: " << test.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        Span test(20000);
        std::vector<int> tab1(10000, 4);
        test.addNumbers(tab1.begin(), tab1.end());
        test.addNumber(-42);
        test.printSpan();
        std::cout << "shortest span: " << test.shortestSpan() << std::endl;
        std::cout << "longest span: " << test.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    Span    sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return (0);
}