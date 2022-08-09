/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:33:15 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 11:40:44 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvertType.hpp"

ConvertType::ConvertType(void) : _typeChar(0),
_typeInt(0), _typeFloat(0), _typeDouble(0)
{
    return ;
}

ConvertType::ConvertType(const ConvertType &cpy)
{
    *this = cpy;
    return ;
}

ConvertType::~ConvertType(void)
{
    return ;    
}

ConvertType &ConvertType::operator=(const ConvertType &convert)
{
    _typeFloat = convert._typeFloat;
    _typeInt = convert._typeInt;
    _typeChar = convert._typeChar;
    _typeDouble = convert._typeDouble;
    return (*this);
}

float   ConvertType::convertInputToFloat(const std::string input)
{
    float stf;

    stf = 0;
    try
    {
        if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
            return (static_cast<float>(input[1]));
        else if (input.size() == 1)
            return (static_cast<float>(input[0]));
        stf = std::stof(input);
    }
    catch(const std::exception& e)
    {
        throw std::string("Impossible to convert the input.");
    }
    return (stf);
}

int     ConvertType::toInt(float nb)
{
    int n = static_cast<int>(nb);
    if (isnan(nb) || nb > std::numeric_limits<int>::max()
        || nb < std::numeric_limits<int>::min())
        throw std::string("impossible");
    return (n);
}

double     ConvertType::toDouble(float nb)
{
    double n = static_cast<double>(nb);
    return (n);
}

char     ConvertType::toChar(float nb)
{
    char    c = static_cast<char>(nb);
    if (isnan(nb) || nb == std::numeric_limits<char>::infinity()
        || nb == -std::numeric_limits<char>::infinity())
        throw std::string("impossible");
    if (c < 32 || c > 126)
        throw std::string("Non displayable");
    return (c);
}

int    ConvertType::printData(std::string input)
{
    try
    {
        _typeFloat = this->convertInputToFloat(input);
    }
    catch(const std::string & e)
    {
        std::cerr << e << '\n';
        return (1);
    }
    try
    {
        _typeChar = this->toChar(_typeFloat);
        std::cout << "char: \'" << _typeChar << "\'" << std::endl;
    }
    catch(const std::string &e)
    {
        std::cout << "char: " << e << std::endl;
    }
    try
    {
        _typeInt = this->toInt(_typeFloat);
        std::cout << "int: " << _typeInt << std::endl;
        
    }
    catch(const std::string &e)
    {
        std::cout << "int: " << e << std::endl;
    }
    if (_typeFloat - static_cast<int>(_typeFloat) == static_cast<float>(0))
        std::cout << "float: " << _typeFloat << ".0f" << std::endl;
    else
        std::cout << "float: " << _typeFloat << "f" << std::endl;
    _typeDouble = this->toDouble(_typeFloat);
    if (_typeDouble - static_cast<int>(_typeDouble) == static_cast<double>(0))
        std::cout << "Double: " << _typeFloat << ".0" << std::endl;
    else
        std::cout << "Double: " << _typeFloat << std::endl;
    return (0);
}