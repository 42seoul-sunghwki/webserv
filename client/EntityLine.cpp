/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityLine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:24:10 by inghwang          #+#    #+#             */
/*   Updated: 2024/07/20 16:24:12 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityLine.hpp"

EntityLine::EntityLine()
{
    completion = false;
}

EntityLine::EntityLine(const EntityLine& src)
{
    completion = src.getCompletion();
    entity = src.getEntity();
}

EntityLine::~EntityLine()
{}

EntityLine& EntityLine::operator=(const EntityLine& src)
{
    completion = src.getCompletion();
    entity = src.getEntity();
    return (*this);
}

bool    EntityLine::getCompletion() const
{
    return (completion);
}

std::vector<std::string>    EntityLine::getEntity() const
{
    return (entity);
}

void    EntityLine::setEntity(std::string &str)
{
    entity.push_back(str);
}

