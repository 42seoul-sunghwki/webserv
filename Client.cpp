/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:11:14 by inghwang          #+#    #+#             */
/*   Updated: 2024/07/08 17:11:16 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client()
{
    fd = -1;
    flag = 0;
    next = NULL;
}

Client::Client(const Client& src)
{
    fd = src.getFd();
    flag = src.getFlag();
    next = src.getNext();
    start[0] = src.getStart(0);
    start[1] = src.getStart(1);
    header[0] = src.getHeader(0);
    header[1] = src.getHeader(1);
    entity[0] = src.getEntity(0);
    entity[1] = src.getEntity(1);
}

Client& Client::operator=(const Client& src)
{
    fd = src.getFd();
    flag = src.getFlag();
    next = src.getNext();
    start[0] = src.getStart(0);
    start[1] = src.getStart(1);
    header[0] = src.getHeader(0);
    header[1] = src.getHeader(1);
    entity[0] = src.getEntity(0);
    entity[1] = src.getEntity(1);
}

Client::~Client()
{}

Client::Client(int fd, Client *next) : fd(fd), next(next)
{}

int Client::getFd(void) const
{
    return (fd);
}

int Client::getFlag(void) const
{
    return (flag);
}

Client  *Client::getNext() const
{
    return (next);
}

std::map<std::string, std::string>  Client::getStart(int i) const
{
    return (start[i]);
}

std::map<std::string, std::string>  Client::getHeader(int i) const
{
    return (header[i]);
}

std::vector<std::string>            Client::getEntity(int i) const
{
    return (entity[i]);
}

void    Client::setFd(int fd)
{
    fd = fd;
}

void    Client::setNext(Client *next)
{
    next = next;
}

void    Client::setStart(int i, std::string first, std::string second)
{
    start[i][first] = second;
}

void    Client::setHeader(int i, std::string first, std::string second)
{
    header[i][first] = second;
}

void    Client::setEntity(int i, std::string elem)
{
    entity[i].push_back(elem);
}

