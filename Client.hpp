/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:11:17 by inghwang          #+#    #+#             */
/*   Updated: 2024/07/08 17:11:19 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <iostream>
#include <map>
#include <vector>

class Client
{
    private:
        int     fd;
        bool    completion;
        std::map<std::string, std::string>  start[2];
        std::map<std::string, std::string>  header[2];
        std::vector<std::string>            entity[2];
        //temp(must delete)
        std::vector<std::string>            temp;
    public:
        Client();
        explicit Client(const Client& src);
        Client& operator=(const Client& src);
        ~Client();
        Client(int fd);
        //get function
        int     getFd(void) const;
        bool    getCompletion(void) const;
        std::map<std::string, std::string>  getStart(int i) const;
        std::map<std::string, std::string>  getHeader(int i) const;
        std::vector<std::string>            getEntity(int i) const;
        //set function
        void    setFd(int fd);
        void    setFlag(bool flag);
        void    setStart(int i, std::string first, std::string second);
        void    setHeader(int i, std::string first, std::string second);
        void    setEntity(int i, std::string elem);
        //temp(must delete)
        void    showTemp(void);
        void    setTemp(std::string str);
};

#endif
