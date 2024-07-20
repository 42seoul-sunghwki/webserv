/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:56:57 by inghwang          #+#    #+#             */
/*   Updated: 2024/07/17 18:56:59 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HeaderLine.hpp"

//header 줄에서 여러 개의 value를 받을 수 있는 key들을 모음
std::vector<std::string>    manyHeaderInit()
{
    std::vector<std::string>    v;

    v.push_back("Accept");
    v.push_back("Accept-Encoding");
    v.push_back("Accept-Language");
    v.push_back("sec-ch-ua");
    return (v);
}

std::vector<std::string>    vitalHeaderInit()
{
    std::vector<std::string>    v;

    v.push_back("Host");
    return (v);
}

std::vector<std::string> HeaderLine::manyHeader = manyHeaderInit();
std::vector<std::string> HeaderLine::vitalHeader = vitalHeaderInit();

bool    HeaderLine::checkMime(std::string temp)
{
    std::istringstream  strStream(temp);
    std::string         str;
    int                 ans;

    ans = 0;
    while (std::getline(strStream, str, '/'))
        ans++;
    if (ans == 2)
        return (true);
    return (false);
}

int HeaderLine::pushValue()
{
    std::vector<std::string>::iterator  it;
    std::istringstream                  strStream(value);
    std::string                         str;
    size_t                              pos;

    it = std::find(manyHeader.begin(), manyHeader.end(), key);
    if (it != manyHeader.end())
    {
        while (std::getline(strStream, str, ','))
        {
            pos = str.find_first_not_of(' ');
            str.erase(0, pos);
            pos = str.find_last_not_of(' ');
            str.erase(pos + 1);
            if (str.empty())
                continue ;
            header[key].push_back(str);
        }
    }
    else
    {
        if (!header[key].empty())
            return (-1);
        header[key].push_back(value);
    }
    return (0);
}

HeaderLine::HeaderLine() : completion(false)
{}

HeaderLine::HeaderLine(const HeaderLine& src)
{
    completion = src.getCompletion();
    entitytype = src.getEntitytype();
    key = src.getKey();
    value = src.getValue();
    header = src.getHeader();
}

HeaderLine::~HeaderLine() {}

HeaderLine& HeaderLine::operator=(const HeaderLine& src)
{
    entitytype = src.getEntitytype();
    completion = src.getCompletion();
    key = src.getKey();
    value = src.getValue();
    header = src.getHeader();
    return (*this);
}

bool    HeaderLine::getCompletion() const
{
    return (completion);
}

ENTITYTYPE  HeaderLine::getEntitytype() const
{
    return (entitytype);
}

std::string HeaderLine::getKey() const
{
    return (key);
}

std::string HeaderLine::getValue() const
{
    return (value);
}
std::map<std::string, std::vector<std::string> > HeaderLine::getHeader() const
{
    return (header);
}

void    HeaderLine::setCompletion(bool temp)
{
    completion = temp;
}

int HeaderLine::plus(std::string temp)
{
    std::string str;
    size_t      colon;
    int         pos;

    // std::cout<<temp<<std::endl;
    pos = temp.find_first_not_of(' ');
    temp.erase(0, pos);
    pos = temp.find_last_not_of(' ');
    temp.erase(pos + 1);
    if (temp.empty())
        return (-1);  //공백만 들어온 상황
    // if (temp[temp.size() - 1] == ',')
    //     temp.erase(temp.size() - 1);
    // std::cout<<temp<<std::endl;
    colon = temp.find(':');
    if (colon != std::string::npos)
    {
        key = temp.substr(0, colon);
        value = temp.substr(colon + 1);
        pos = value.find_first_not_of(' ');
        value.erase(0, pos);
        pos = value.find_last_not_of(' ');
        value.erase(pos + 1);
        // std::cout<<"key: "<<key;
        if (pushValue() < 0)
            return (-2);
        // header[key].push_back(str);
    }
    else
    {
        if (key.size() == 0 && !checkMime(temp))
            return (-2);  //message/htpp타입이 아닌데 obs-fold를 사용한 상황
        value = temp;
        if (pushValue() < 0)
            return (-2);
    }
    return (0);
}

int HeaderLine::headerError()
{
    std::vector<std::string>::iterator                          itv;
    std::map<std::string, std::vector<std::string> >::iterator  itm;

    for (itv = vitalHeader.begin(); itv != vitalHeader.end(); itv++)
    {
        itm = header.find(*itv);
        if (itm == header.end())
            return (-1);
    }
    itm = header.find("Content-Length");
    if (itm == header.end())
    {
        entitytype = TRANSFER;
        itm = header.find("Transfer-Encoding");
        if (itm == header.end())
            entitytype = NOT;
    }
    else
    {
        entitytype = CONTENT;
        itm = header.find("Transfer-Encoding");
        if (itm != header.end())
        {
            entitytype = NOT;
            return (-2);
        }
    }
    return (0);
}

