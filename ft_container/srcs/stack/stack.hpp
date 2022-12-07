/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:21:20 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:29:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "../vector/vector.hpp"

namespace ft
{
    template<class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container                            container_type;
            typedef typename Container::value_type       value_type;
            typedef typename Container::size_type        size_type;
            typedef typename Container::reference        reference;
            typedef typename Container::const_reference  const_reference;

            explicit stack(const Container& cont = Container() ): c(cont){};
            stack( const stack& other ){*this = other;};
            ~stack(){};
            stack& operator=( const stack& other ){c = other.c; return (*this);};

            reference top(){return (*(c.rbegin()));};
            const_reference top() const {return (*(c.rbegin()));};
            bool empty() const {return (c.empty());};
            size_type size() const {return (c.size());};
            void push( const value_type& value ){c.push_back(value);};
            void pop(){c.pop_back();};

            template <class T1, class T2>
            friend bool operator==( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );
            template <class T1, class T2>
            friend bool operator<( const ft::stack<T1,T2>& lhs, const ft::stack<T1,T2>& rhs );
 
            
        protected:
            container_type  c;        
    };

    template< class T, class Container >
    bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {return (lhs.c == rhs.c);};

    template< class T, class Container >
    bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {return (!(lhs == rhs));};

    template< class T, class Container >
    bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {return (lhs.c < rhs.c);};

    template< class T, class Container >
    bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {return (!(lhs > rhs));};

    template< class T, class Container >
    bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {return (lhs >= rhs && lhs != rhs);};

    template< class T, class Container >
    bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {return (!(lhs < rhs));};

    template< class T, class Container >
    std::ostream &operator<<(std::ostream &o, const ft::stack<T, Container>& stk)
    {o << stk.c; return (o);};
}

#endif