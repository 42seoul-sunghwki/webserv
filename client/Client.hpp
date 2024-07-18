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

# include "StartLine.hpp"
# include "HeaderLine.hpp"
// # include <iostream> 
// # include <map>
# include <vector>
# include <queue>

typedef struct Request
{
    bool    fin;
    Method  method;
    Version version;
    std::string url;
    std::map<std::string, std::vector<std::string> >  header;
}   Request;

class Client
{
    private:
        int         fd;
        std::string msg;
        Request     request;
        StartLine   startline;
        HeaderLine  headerline;
        std::vector<std::string>            entity[2];
        //temp(must delete)
        std::queue<std::string>            message;
    public:
        Client();
        explicit Client(const Client& src);
        Client& operator=(const Client& src);
        ~Client();
        Client(int fd);
        //get function
        int         getFd(void) const;
        StartLine   getStartLine(void) const;
        std::vector<std::string>            getEntity(int i) const;
        //set function
        void    setFd(int fd);
        int     setStartLine(void);
        int     setHeaderUtil(std::string temp);
        int     setHeader(void);
        void    setEntity(int i, std::string elem);
        //temp(must delete)
        void    showMessage(void);
        void    setMessage(std::string str);
};

#endif
