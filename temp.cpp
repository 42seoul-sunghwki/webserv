#include <iostream>
#include <map>
#include <sstream>

enum    NUM
{
    ONE = 1, 
    TWO,
    THREE,
    FOUR
};

int main()
{
    std::istringstream test("ONE   TWO  THREE  hi  THREE");
    std::string         str;
    NUM num;
    std::map<std::string, std::string> m;
    m["ONE"] = "ONE";
    m["TWO"] = "TWO";
    m["THREE"] = "THREE";
    while (std::getline(test, str, ' '))
    {
        if (m[str] == "\0")
            std::cout<<"here";
        std::cout<<str<<": "<<m[str]<<std::endl;
    }
    std::cout<<"\n\n======test2=======\n";
    std::istringstream  test2("hi   ");
    while (std::getline(test2, str, ':'))
    {
        std::cout<<str<<"\n";
    }
    std::cout<<"\n\n=======test3=======\n";
    std::string test3 = "HI,";
    test3.erase(2);
    std::cout<<test3<<std::endl;
    test3.clear();
    std::cout<<test3<<"here"<<std::endl;
    std::cout<<"\n\n=======test4=======\n";
    std::string test4 = "HI Hello World";
    std::cout<<test4.substr(0, 4)<<std::endl;
    std::cout<<test4.substr(4)<<std::endl;
    return 0;
}

string

std::string str[6] = {"", "http1.1"};

http11 = 1;

str[http11] = input_str;