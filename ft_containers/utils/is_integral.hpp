/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:25:32 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/09/15 17:00:26 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
    template <typename T>
    struct is_integral
    {
        enum {value = false};
    };
    
    template<>
    struct is_integral<bool>
    {
        enum {value = true};
    };
    
    template<>
    struct is_integral<char>
    {
        enum {value = true};
    };

    template<>
    struct is_integral<char16_t>
    {
        enum {value = true};
    };

    template<>
    struct is_integral<char32_t>
    {
        enum {value = true};
    };

    template<>
    struct is_integral<wchar_t>
    {
        enum {value = true};
    };

    template<>
    struct is_integral<signed char>
    {
        enum {value = true};
    };

    template<>
    struct is_integral<unsigned char>
    {
        enum {value = true};
    };

    template<>
    struct is_integral<short int>
    {
       enum {value = true};
    };
    
    template<>
    struct is_integral<int>
    {
       enum {value = true};
    };

    template<>
    struct is_integral<long int>
    {
       enum {value = true};
    };

    template<>
    struct is_integral<long long int>
    {
       enum {value = true};
    };

    template<>
    struct is_integral<unsigned int>
    {
       enum {value = true};
    };

    template<>
    struct is_integral<unsigned short int>
    {
       enum {value = true};
    };

    template<>
    struct is_integral<unsigned long int>
    {
       enum {value = true};
    };

    template<>
    struct is_integral<unsigned long long int>
    {
       enum {value = true};
    };   
}

#endif