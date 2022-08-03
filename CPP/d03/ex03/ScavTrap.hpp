/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:46:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 16:23:31 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    ScavTrap(void);
    int _guardGateStatus;
public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &cpy);
    ~ScavTrap(void);
    ScavTrap    &operator=(ScavTrap const &scav2);

    void    guardGate(void);
    void    attack(const std::string &target);
};

#endif

