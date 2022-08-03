/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:29:46 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 16:53:59 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "includes.h"

class   Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain(void);
        Brain(const Brain &cpy);
        ~Brain(void);
        Brain   &operator=(Brain const &brain2);

        void    addIdeas(std::string idea);
        void    getIdeas(void);
};

#endif