/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:46:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/01 17:57:19 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
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

