/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:36:52 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/11 15:37:07 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _vector(0), _maxSize(0)
{
    return ;
}

Span::Span(const unsigned int N) : _vector(0), _maxSize(N)
{
    return ;
}

Span::Span(const Span &cpy)
{
    *this = cpy;
    return ;
}

Span::~Span(void)
{
    return ;
}

Span &Span::operator=(const Span &span)
{
    _vector = span._vector;
    return (*this);
}

void    Span::addNumber(int n)
{
    if (_vector.size() == _maxSize)
        throw std::out_of_range("span is full. You can't add any numbers.");
    _vector.push_back(n);
}

void    Span::printSpan(void)
{
    for_each(_vector.begin(), _vector.end(), ::print<int>);
    return ;
}

int     Span::shortestSpan(void)
{
    int rslt;
    std::vector<int>::size_type i = 1;

    if (_vector.size() <= 1)
        throw std::out_of_range("Span have less than 2 value.");
    std::vector<int> temp = _vector;
    std::sort(temp.begin(), temp.end());
    rslt = abs(temp[0] - temp[1]);
    while (i + 1 < temp.size())
    {
        if (abs(temp[i] - temp[i + 1]) < rslt)
            rslt = abs(temp[i] - temp[i + 1]);
        i++;
    }
    return (rslt);
}

int     Span::longestSpan(void)
{
    if (_vector.size() <= 1)
        throw std::out_of_range("Span have less than 2 value.");
    return (*std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end()));
}

void    Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_vector.size() + (end - begin) > _maxSize)
        throw std::out_of_range("span is full. You want to add too many numbers");
    _vector.insert(_vector.end(), begin, end);
    return ;
}