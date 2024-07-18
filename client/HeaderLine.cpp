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

bool    HeaderLine::checkMime(std::string temp)
{
    std::istringstream  strStream(temp);
    std::string         str;
    int                 ans;

    ans = 0;
    while (std::getline(strStream, str, '/'))
    {
        ans++;
    }
    if (ans == 2)
        return (true);
    return (false);
}

HeaderLine::HeaderLine() : completion(false)
{}

HeaderLine::HeaderLine(const HeaderLine& src)
{
    completion = src.getCompletion();
    key = src.getKey();
    value = src.getValue();
    header = src.getHeader();
}

HeaderLine::~HeaderLine() {}

HeaderLine& HeaderLine::operator=(const HeaderLine& src)
{
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
    size_t  colon;
    int     pos;

    pos = temp.find_first_not_of(' ');
    temp.erase(0, pos);
    pos = temp.find_last_not_of(' ');
    temp.erase(pos + 1);
    if (temp.size() == 0)
        return (-1);  //공백만 들어온 상황
    if (temp[temp.size() - 1] == ',')
        temp.erase(temp.size() - 1);
    colon = temp.find(':');
    if (colon != std::string::npos)
    {
        key = temp.substr(0, colon);
        value.clear();
        value = temp.substr(colon);
        header[key].push_back(value);
    }
    else
    {
        if (key.size() == 0 && !checkMime(temp))
            return (-2);  //message/htpp타입이 아닌데 obs-fold를 사용한 상황
        header[key].push_back(value);
    }
    return (0);
}

