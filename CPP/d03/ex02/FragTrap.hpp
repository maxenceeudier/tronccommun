/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:46:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 10:06:17 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
private:
    FragTrap(void);
public:
    FragTrap(std::string name);
    FragTrap(FragTrap const &cpy);
    ~FragTrap(void);
    FragTrap    &operator=(FragTrap const &Frag2);

    void    highFivesGuys(void);
};

#endif

