/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:49:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/13 11:49:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map/map.h"
#include <string>

void test_map()
{
    ft::map<std::string, int> map;
    map.insert(ft::mapIterator<ft::pair<std::string, int> >(), ft::mapIterator<ft::pair<std::string, int> >());    
}

int main()
{
    test_map();
    return (0);
}