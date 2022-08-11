/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:33:01 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/11 13:00:23 by maxenceeudi      ###   ########.fr       */
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