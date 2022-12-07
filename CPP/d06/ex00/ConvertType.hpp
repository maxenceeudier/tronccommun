/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertType.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:32:00 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/22 22:01:39 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_TYPE_HPP
#define CONVERT_TYPE_HPP
#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>

class ConvertType
{
private:
    char    _typeChar;
    int     _typeInt;
    float   _typeFloat;
    double  _typeDouble;
    int     _intLim;
    
public:
    ConvertType(void);
    ConvertType(const ConvertType &cpy);
    ~ConvertType(void);
    ConvertType &operator=(const ConvertType &convert);

    int    printData(std::string input);
    
    float   convertInputToLD(const std::string &input);
    int     toInt(float nb);
    double  toDouble(float nb);
    char    toChar(float nb);    
};

#endif