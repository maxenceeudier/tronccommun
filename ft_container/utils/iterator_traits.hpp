/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:51:06 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/21 07:57:11 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include  <cstddef>

namespace ft
{
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };
    
    template< class Iter >
    struct iterator_traits
    {
        typedef typename Iter::difference_type   difference_type;
        typedef typename Iter::value_type        value_type;
        typedef typename Iter::pointer           pointer;
        typedef typename Iter::reference         reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template< class T >
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t  difference_type;
        typedef T               value_type;
        typedef T*              pointer;
        typedef T&              reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };
    
    template< class T >
    struct iterator_traits<const T*>
    {
        typedef std::ptrdiff_t      difference_type;
        typedef T                   value_type;
        typedef const T*            pointer;
        typedef const T&            reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };
}


#endif