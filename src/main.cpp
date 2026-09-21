#include <iostream>
#include <string>
#include <vector>

#include "parser.hpp"

int main()
{
    std::string input;

    while (true)
    {

        std::cout << "nsh> ";
        std::getline(std::cin, input);

        std::cout << "You entered: " << input << '\n';

        std::vector<std::string> args = tokenize(input);

        for (const auto& arg : args)
        {
            std::cout << arg << ' ';
        }
        std::cout << '\n';

    }

    return 0;
}