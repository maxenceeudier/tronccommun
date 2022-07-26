/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:43:06 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 20:20:54 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP 
# include <string>

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warnig(void);
    void    error(void);
public:
    Harl();
    ~Harl();
    
    void    complain(std::string level);
};

#endif
