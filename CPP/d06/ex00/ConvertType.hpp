/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertType.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:32:00 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 11:20:30 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_TYPE_HPP
#define CONVERT_TYPE_HPP
#include <iostream>
#include <cmath>

class ConvertType
{
private:
    char    _typeChar;
    int     _typeInt;
    float   _typeFloat;
    double  _typeDouble;
    
public:
    ConvertType(void);
    ConvertType(const ConvertType &cpy);
    ~ConvertType(void);
    ConvertType &operator=(const ConvertType &convert);

    int    printData(std::string input);
    
    float   convertInputToFloat(const std::string input);
    int     toInt(float nb);
    double  toDouble(float nb);
    char    toChar(float nb);    
};

#endif