/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:37:02 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/09/15 18:09:55 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP
#include <cstdlib>
#include <iostream>

namespace ft
{
    template <typename Tkey, typename Tvalue>
    class pair
    {
        public:
            pair<Tkey, Tvalue>(void) {};
            template <typename U, typename V>
            pair<Tkey, Tvalue>(const pair<U, V> &pr)
            {
                first = static_cast<Tkey>(pr.first);
                second = static_cast<Tvalue>(pr.second);
                return ;
            };
            pair<Tkey, Tvalue>(const Tkey &key, const Tvalue &val) : first(key), \
            second(val) {};
            ~pair<Tkey, Tvalue>(void) {};
            pair<Tkey, Tvalue>  &operator=(const pair<Tkey, Tvalue> &pr)
            {
                first = pr.first;
                second = pr.second;
                return (*this);
            };
            Tkey    first;
            Tvalue  second;
    };

    template<typename Tkey, typename Tvalue>
    pair<Tkey, Tvalue> make_pair (Tkey x, Tvalue y)
    {
        return (pair<Tkey ,Tvalue>(x,y));
    }

    template<typename Tkey, typename Tvalue>
    bool    operator==(const pair<Tkey, Tvalue> &pr1, const pair<Tkey, Tvalue> &pr2)
    {
        return (pr1.first == pr2.first && pr1.second == pr2.second);
    }

    template<typename Tkey, typename Tvalue>
    bool    operator!=(const pair<Tkey, Tvalue> &pr1, const pair<Tkey, Tvalue> &pr2)
    {
        return (!(pr1 == pr2));
    }

    template<typename Tkey, typename Tvalue>
    std::ostream	&operator<<(std::ostream &o, pair<Tkey, Tvalue> const &i)
    {
        std::cout << "key = " << i.first \
        << ", value = " << i.second << " " << std::endl;
        return (o);
    }
}
#endif