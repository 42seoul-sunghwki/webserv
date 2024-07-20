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

Client::Client() : fd(-1)
{}

Client::Client(const Client& src) : fd(src.getFd()), startline(src.getStartLine())
{
    entity[0] = src.getEntity(0);
    entity[1] = src.getEntity(1);
}

Client& Client::operator=(const Client& src)
{
    fd = src.getFd();
    startline = src.getStartLine();
    entity[0] = src.getEntity(0);
    entity[1] = src.getEntity(1);
    return (*this);
}

Client::~Client()
{
    std::cout<<"client close"<<std::endl;
}

Client::Client(int fd) : fd(fd)
{}

int Client::getFd(void) const
{
    return (fd);
}

StartLine   Client::getStartLine(void) const
{
    return (startline);
}

std::vector<std::string>            Client::getEntity(int i) const
{
    return (entity[i]);
}

void    Client::setFd(int fd)
{
    this->fd = fd;
}

int Client::setStartLine(void)
{
    size_t      flag;

    if (message.size())
    {
        msg += message.back();
        message.pop();
    }
    // std::cout<<"msg: "<<msg<<"\n";
    flag = msg.find("\r\n");
    if (flag != std::string::npos)
    {
        // std::cout<<"plus msg: "<<msg.substr(0, flag - 1)<<"\n";
        if (startline.plus(msg.substr(0, flag)) < 0)
            return (-1);  //시작줄 에러
        msg = msg.substr(flag + 2);
        // std::cout<<"msg: "<<msg<<"\n";
        request.method = startline.getMethod();
        request.url = startline.getUrl();
        request.version = startline.getVersion();
    }
    return (0);
}

int Client::setHeader(void)
{
    size_t      flag;
    std::string str;

    if (message.size())
    {
        msg += message.back();
        message.pop();
    }
    while (1)
    {
        flag = msg.find("\r\n");
        if (flag != std::string::npos)
        {
            if (flag == 0)
            {
                if (headerline.headerError() < 0)
                    return (-2);  //vital header not or header double
                headerline.setCompletion(true);
                request.header = headerline.getHeader();
                //여기서 header 오류 체크
                break ;
            }
            if (headerline.plus(msg.substr(0, flag)) < 0)
                return (-1);  //헤더 에러
            msg = msg.substr(flag + 2);
        }
        else
            break ;
    }
    return (0);
}

void    Client::setEntity(int i, std::string elem)
{
    entity[i].push_back(elem);
}

//temp(must delete)
void    Client::showMessage(void)
{
    std::vector<std::string>::iterator  itv;
    //request 출력
    std::cout<<"=====strat line=====\n";
    std::cout<<request.method<<" "<<request.version<<" "<<request.url<<std::endl;
    std::cout<<"=====header line=====\n";
    for (std::map<std::string, std::vector<std::string> >::iterator it = request.header.begin(); it != request.header.end(); it++)
    {
        std::cout<<it->first<<": ";
        for (itv = request.header[it->first].begin(); itv != request.header[it->first].end(); itv++)
            std::cout<<*itv<<"  ";
        std::cout<<"\n";
    }
    while (!message.empty())
    {
        std::cout<<message.front();
        message.pop();
    }
}

void    Client::setMessage(std::string str)
{
    message.push(str);
    if (!startline.getCompletion())
    {
        if (setStartLine() < 0)
            return ;  //여기서 에러 처리하기
    }
    if (startline.getCompletion() && !headerline.getCompletion())
    {
        if (setHeader() < 0)
            return ;  //여기서 에러 처리하기
    }
}

