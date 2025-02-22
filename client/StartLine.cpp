/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Startline.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:55:24 by inghwang          #+#    #+#             */
/*   Updated: 2024/07/17 12:55:25 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StartLine.hpp"

std::map<std::string, Method> originMethodInit()
{
    std::map<std::string, Method> m;

    m["GET"] = GET;
    m["HEAD"] = HEAD;
    m["POST"] = POST;
    m["DELETE"] = DELETE;
    return m;
}

std::map<std::string, Version> originVersionInit()
{
    std::map<std::string, Version> m;

    m["HTTP/1.0"] = HTTP10;
    m["HTTP/1.1"] = HTTP11;
    m["HTTP/1.2"] = HTTP12;
    m["HTTP/2.0"] = HTTP20;
    m["HTTP/3.0"] = HTTP30;
    return m;
}

// 여기에 정의를 추가하세요
std::map<std::string, Method> StartLine::originMethod = originMethodInit();
std::map<std::string, Version> StartLine::originVersion = originVersionInit();

StartLine::StartLine() : completion(false)
{}

StartLine::StartLine(const StartLine& src) : completion(src.getCompletion()), method(src.getMethod()), version(src.getVersion()), url(src.getUrl())
{}

StartLine&  StartLine::operator=(const StartLine& src)
{
    // completion = src.getCompletion();
    completion = src.completion;
    method = src.getMethod();
    version = src.getVersion();
    url = src.getUrl();
    return (*this);
}

StartLine::~StartLine()
{}

bool        StartLine::getCompletion() const
{
    return (completion);
}

Method  StartLine::getMethod() const
{
    return (method);
}

Version StartLine::getVersion() const
{
    return (version);
}

std::string  StartLine::getUrl() const
{
    return (url);
}

int     StartLine::plus(std::string temp)
{
    std::istringstream  strStream(temp);
    std::string         str;
    int                 answer;

    answer = 0;
    // std::cout<<temp<<std::endl;
    while (getline(strStream, str, ' '))
    {
        if (answer > 2)
            return (-4);
        switch (answer)
        {
            case 0:
                method = originMethod[str];
                if (method == 0)
                    return (-1);
                // std::cout<<str<<": "<<method<<"\n";
                break ;
            case 1:
                if (str.empty())
                    return (-2);
                url = str;
                // std::cout<<str<<": "<<url<<"\n";
                break ;
            case 2:
                version = originVersion[str];
                // std::cout<<str<<": "<<version<<std::endl;
                if (version == 0)
                    return (-3);
                // std::cout<<str<<": "<<version<<std::endl;
                break ;
            default:
                break ;
        }
        answer++;
    }
    completion = true;
    return (0);
}




