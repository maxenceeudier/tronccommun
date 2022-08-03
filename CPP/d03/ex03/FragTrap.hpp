/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:46:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 16:53:45 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap
{
protected:
    FragTrap(void);
    unsigned int    hit;
    unsigned int    _damage;
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &cpy);
    ~FragTrap(void);
    FragTrap    &operator=(FragTrap const &Frag2);

    void    highFivesGuys(void);
    unsigned int    getHit(void) const;
    unsigned int    getDamage(void) const;
};

#endif

