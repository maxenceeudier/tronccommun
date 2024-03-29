/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:51:03 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 14:16:39 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorHeader.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/is_integral.hpp"
#include "../../utils/distance.hpp"

namespace ft
{
    template <class T, class Allocator>
    vector<T, Allocator>::vector(const Allocator& alloc)\
    : _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL){}

    template <class T, class Allocator>
    vector<T, Allocator>::vector(size_type count, const T &value, const Allocator &alloc)\
    : _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL)
    {this->insert(_end, count, value);}
    
    template <class T, class Allocator>
    vector<T, Allocator>::vector(const vector &cpy)\
    : _alloc(cpy.get_allocator()), _start(NULL), _end(NULL), _end_capacity(NULL)
    {*this = cpy;}
    
    template <class T, class Allocator>
    vector<T, Allocator>::~vector(void)
    {
        this->clear();
        _alloc.deallocate(_start, this->capacity());
    }

    

            
    template <class T, class Allocator>  
    vector<T, Allocator>  &vector<T, Allocator>::operator=(const vector &rhs)
    {
        this->clear();
        this->insert(_end, rhs.begin(), rhs.end());

        return (*this);
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::assign(size_type count, const T &value)
    {
        this->clear();
        this->insert(this->end(), count, value);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const
    {return (_alloc);}
}