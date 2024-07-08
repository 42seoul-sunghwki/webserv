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
        int fd;
        int flag;
        Client                              *next;
        std::map<std::string, std::string>  start[2];
        std::map<std::string, std::string>  header[2];
        std::vector<std::string>            entity[2];
        Client();
    public:
        Client(const Client& src);
        Client& operator=(const Client& src);
        ~Client();
        Client(int fd, Client *next);
        //get function
        int getFd(void) const;
        int getFlag(void) const;
        Client  *getNext() const;
        std::map<std::string, std::string>  getStart(int i) const;
        std::map<std::string, std::string>  getHeader(int i) const;
        std::vector<std::string>            getEntity(int i) const;
        //set function
        void    setFd(int fd);
        void    setNext(Client *next);
        void    setStart(int i, std::string first, std::string second);
        void    setHeader(int i, std::string first, std::string second);
        void    setEntity(int i, std::string elem);
};

#endif
