#include <iostream>
#include <vector>
#include <string>

#include "parser.hpp"

int main()
{   
    std::string input = "ls -la /home";

    std::vector<std::string> actual = tokenize(input);
    std::vector<std::string> expected = {"ls", "-la", "/home"};

    if ( actual == expected)
    {
        std::cout << "[PASS]\n";
    }
    else
    {
        std::cout << "[FAIL]\n";
    }
}