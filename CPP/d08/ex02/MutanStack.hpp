/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:46:58 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/11 16:43:11 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANtSTACK_HPP
#define MUTANtSTACK_HPP
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

template<typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T, U>
{
public:
    MutantStack<T, U>(void) : std::stack<T, U>()
    {
        return ;
    };
    MutantStack<T, U>(U &data) : std::stack<T, U>(data)
    {
        return ;
    };
    MutantStack<T, U>(const MutantStack<T, U> &cpy) : std::stack<T, U>(cpy)
    {
        return ;
    };
    virtual ~MutantStack<T, U>(void)
    {
        return ;
    };
    MutantStack<T, U> &operator=(const MutantStack<T, U> &mutan)
    {
        std::stack<T, U>::operator=(mutan);
        return (*this);
    };
    typedef typename std::stack<T, U>::container_type::iterator iterator;
    typedef typename std::stack<T, U>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T, U>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T, U>::container_type::const_reverse_iterator const_reverse_iterator;
    iterator                begin(void) {return (this->c.begin());};
    iterator                end(void)   {return (this->c.end());};
    const_iterator          cbegin(void) {return (this->c.cbegin());};
    const_iterator          cend(void)   {return (this->c.cend());};
    reverse_iterator        rbegin(void) {return (this->c.rbegin());};
    reverse_iterator        rend(void)   {return (this->c.rend());};
    const_reverse_iterator  crbegin(void) {return (this->c.crbegin());};
    const_reverse_iterator  crend(void)   {return (this->c.crend());};
};

#endif