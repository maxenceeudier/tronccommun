/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:36:18 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/11 15:28:03 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
T   abs(T data)
{
    return (data < 0 ? -data : data);
}

template<typename T>
void    print(T data)
{
    std::cout << data << std::endl;
    return ;
}

class Span
{
private:
    Span(void);
    std::vector<int> _vector;
    unsigned int     _maxSize;         
public:
    Span(const unsigned int N);
    Span(const Span &cpy);
    ~Span(void);
    Span &operator=(const Span &span);

    void    addNumber(int n);
    void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void    printSpan(void);
    int     shortestSpan(void);
    int     longestSpan(void);
  
};



#endif