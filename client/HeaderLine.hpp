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

class HeaderLine
{
    private:
        bool        completion;
        std::string str;
        std::string key;
        std::string value;
        std::map<std::string, std::vector<std::string> > header;
        bool    checkMime(std::string temp);
        void    pushValue();
    public:
        static std::vector<std::string>  manyHeader;
        HeaderLine();
        HeaderLine(const HeaderLine& src);
        ~HeaderLine();
        HeaderLine& operator=(const HeaderLine& src);
        //get function
        bool        getCompletion() const;
        std::string getKey() const;
        std::string getValue() const;
        std::map<std::string, std::vector<std::string> > getHeader() const;
        //set function
        void    setCompletion(bool temp);
        int plus(std::string temp);
};

#endif
