/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:57:00 by inghwang          #+#    #+#             */
/*   Updated: 2024/07/17 18:57:02 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERLINE_HPP
# define HEADERLINE_HPP

# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <algorithm>

enum    ENTITYTYPE 
{
    CONTENT = 1,
    TRANSFER,
    NOT
};

class HeaderLine
{
    private:
        bool        completion;
        ENTITYTYPE  entitytype;
        std::string key;
        std::string value;
        std::map<std::string, std::vector<std::string> > header;
        bool    checkMime(std::string temp);
        int     pushValue();
    public:
        static std::vector<std::string> manyHeader;
        static std::vector<std::string> vitalHeader;
        HeaderLine();
        HeaderLine(const HeaderLine& src);
        ~HeaderLine();
        HeaderLine& operator=(const HeaderLine& src);
        //get function
        bool        getCompletion() const;
        ENTITYTYPE  getEntitytype() const;
        std::string getKey() const;
        std::string getValue() const;
        std::map<std::string, std::vector<std::string> > getHeader() const;
        //set function
        void    setCompletion(bool temp);
        //logic
        int plus(std::string temp);
        int headerError();
};

#endif
