/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:50:29 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 12:35:44 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/stack/Stack.hpp"

void    test_stack()
{
    ft::stack<int> stack;

    std::cout << "stack:\n";
    std::cout << "size - empty\n";
    std::cout << stack.size() << " - " << stack.empty();
    std::cout << std::endl << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "push 1, 2, 3:\n";
    std::cout << "top - size - empty:\n";
    std::cout << stack.top() << " - " << stack.size() << " - " << stack.empty();
    std::cout << std::endl << std::endl;
    
    std::cout << "while(size) -> top -> pop:\n";
    size_t i = stack.size();
    while (i--)
    {
        std::cout << stack.top();
        stack.pop();
    }
    std::cout << std::endl << std::endl;

    std::cout << "size - empty\n";
    std::cout << stack.size() << " - " << stack.empty();
}

int main()
{
    test_stack();
    return (0);
}