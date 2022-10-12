/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_std.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:52:48 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 14:38:17 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <vector>
#include <iostream>


void    test_stack()
{
    std::stack<int> stack;

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
    std::cout << std::endl << std::endl;

    std::vector<int>    vec(10, 3);
    std::stack<int, std::vector<int> >  stack2(vec);
    std::cout << "vec(10, 3); stack2(vec)\n";
    std::cout << "while(size) -> top -> pop:\n";
    i = stack2.size();
    while (i--)
    {
        std::cout << stack2.top();
        stack2.pop();
    }
    std::cout << std::endl << std::endl;

}

int main()
{
    test_stack();
    return (0);
}