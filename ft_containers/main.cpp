#include "./Include/include.h"


int main()
{
    std::cout << "\n\noperators" << std::endl;
    ft::map<std::string, int> m3;
    ft::map<std::string, int> m4;
    m3.insert(ft::pair<std::string, int>("hello1", 1));
    m3.insert(ft::pair<std::string, int>("hello2", 2));
    m3.insert(ft::pair<std::string, int>("hello3", 3));

    m4.insert(ft::pair<std::string, int>("hello1", 1));
    m4.insert(ft::pair<std::string, int>("hello2", 2));
    m4.insert(ft::pair<std::string, int>("hello3", 4));

    std::cout << m4;

    ft::vector<std::string> vec;
    vec.push_back("yoo");
    ft::vector<std::string>::iterator it = vec.begin();
    it++;

    std::cout << m4;
    return (0);
}