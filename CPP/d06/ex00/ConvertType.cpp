/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:33:15 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/22 22:35:29 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvertType.hpp"

ConvertType::ConvertType(void) : _typeChar(0),
_typeInt(0), _typeFloat(0), _typeDouble(0), _intLim(0)
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
    _intLim = convert._intLim;
    return (*this);
}

float  ConvertType::convertInputToLD(const std::string &input)
{
    float stf;
    long double range;
    std::stringstream ss(input);
    ss >> range;

    stf = 0;
    try
    {
        if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
            return (static_cast<float>(input[1]));
        else if (input.size() == 1 && (input[0] < '0' || input[0] > '9'))
            return (static_cast<float>(input[0]));
        else if (range < -2147483648 || range > 2147483647)
            _intLim = 1;
        else if (range <= 2147483647 && range >= -2147483648)
            _typeInt = static_cast<int>(range);
        stf = ::atof(input.data());
    }
    catch(const std::exception& e)
    {
        throw std::string("Impossible to convert the input.");
    }
    return (stf);
}

int     ConvertType::toInt(float nb)
{
    int n = static_cast<int>((nb));
    if (std::isnan(nb) || _intLim || nb == std::numeric_limits<float>::infinity()
        || nb == -std::numeric_limits<float>::infinity())
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

    if (nb && (std::isnan(nb) || nb == std::numeric_limits<float>::infinity()
        || nb == -std::numeric_limits<float>::infinity()))
        throw std::string("impossible");
    if (c < 32 || c > 126)
        throw std::string("Non displayable");
    return (c);
}

int    ConvertType::printData(std::string input)
{
    try
    {
        _typeFloat = this->convertInputToLD(input);
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
        if (!_typeInt)
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
        std::cout << "Double: " << _typeDouble << ".0" << std::endl;
    else
        std::cout << "Double: " << _typeDouble << std::endl;
    std::cout << std::endl;
    return (0);
}