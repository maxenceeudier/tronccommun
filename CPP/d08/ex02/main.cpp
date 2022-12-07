/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:46:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/11 17:11:52 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"

int main()
{
    std::vector<int> myvector (2,200);

    ::MutantStack<int, std::vector<int> > vec(myvector);
    vec.push(2);
    vec.push(3);
    ::MutantStack<int, std::vector<int> >::reverse_iterator itr = vec.rbegin();
    ::MutantStack<int, std::vector<int> >::reverse_iterator iter = vec.rend();
    while (itr != iter)
    {
        std::cout << *itr << std::endl;
        ++itr;
    }
    std::cout << std::endl << std::endl;

    ::MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() <<std::endl;
    mstack.pop();
    std::cout << mstack.size() <<std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737); 
    mstack.push(0);
    
    ::MutantStack<int>::iterator it = mstack.begin();
    ::MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while(it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl << std::endl;
    
    std::list<int>    list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() <<std::endl;
    list.pop_back();
    std::cout << list.size() <<std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737); 
    list.push_back(0);
    
    std::list<int>::iterator itl = list.begin();
    std::list<int>::iterator itel = list.end();
    ++itl;
    --itl;
    while(itl != itel)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }
    return (0);
}