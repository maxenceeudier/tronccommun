/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:18:11 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 13:14:45 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
private:
    T                   *_array;
    unsigned int  _size;
public:
    Array<T>(void) : _array(NULL), _size(0){};
    Array<T>(const unsigned int n) : _size(n)
    {
        if (static_cast<int>(n) < 0)
            throw std::string("overflow error");
        _array = new T[n];
    };
    Array<T>(const Array<T> &cpy)
    {
        *this = cpy;
        return ;
    };
    Array<T>    &operator=(const Array<T> &cpy)
    {
        unsigned int i = 0;

        _size = cpy._size;
        _array = new T[_size];
        while (i < _size)
        {
            _array[i] = cpy._array[i];
            i++; 
        }
        return (*this);
    };
    ~Array<T>(void)
    {
        if (_size > 0)
            delete [] _array;
    };
    T   &operator[](unsigned int index)
    {
        if (index >= _size || index < 0)
            throw std::string("overflow error");
        return (_array[index]);
    }
    unsigned int  size(void)
    {
        return (_size);
    };
};



#endif