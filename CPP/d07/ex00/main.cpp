/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:38:20 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 09:50:09 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main ()
{
    int a = 2;
    int b = 3;

    ::swap(a,b);
    std::cout << "a = " << a << ", b = " <<b << std::endl;
    std::cout << "min(a,b) = " << ::min(a,b) <<std::endl;
    std::cout << "max(a,b) = " << ::max(a,b) <<std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c,d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c,d) = " << ::min(c,d) << std::endl;
    std::cout << "max(c,d) = " << ::max(c,d) << std::endl;
    
    return (0);
}