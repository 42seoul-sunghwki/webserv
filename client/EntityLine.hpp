/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityLine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:24:14 by inghwang          #+#    #+#             */
/*   Updated: 2024/07/20 16:24:15 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYLINE_HPP
# define ENTITYLINE_HPP

# include "HeaderLine.hpp"

class EntityLine
{
    private:
        bool                        completion;
        std::vector<std::string>    entity; 
    public:
        EntityLine();
        EntityLine(const EntityLine& src);
        ~EntityLine();
        EntityLine& operator=(const EntityLine& src);
        //get function
        bool    getCompletion() const;
        std::vector<std::string>    getEntity() const;
        //logic
        void    setEntity(std::string &str);
        void    setCompletion(bool temp);
}

#endif
