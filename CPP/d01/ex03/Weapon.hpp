/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:21:11 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 12:32:28 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string> 

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    ~Weapon();
    
    const std::string   &getType(void);
    void                setType(std::string std);
};

#endif