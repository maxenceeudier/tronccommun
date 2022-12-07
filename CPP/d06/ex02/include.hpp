/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:15:42 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 17:24:21 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <cstdlib>

class Base {public: virtual ~Base(void){}};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);
#endif