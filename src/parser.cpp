#include "parser.hpp"

// remove this comment later.
// this separates input into individual parts.
// "ls -la" -> "ls", "-la"

std::vector<std::string> tokenize(const std::string& input)
{
    std::string current_args;
    std::vector<std::string> args;


    for (int i = 0; i < input.size(); i++)
        {

            if (input[i] == ' ')
            {

                if (!current_args.empty())
                {
                    args.push_back(current_args);
                }

                current_args.clear();
            }
            else
            {
                current_args += input[i];
            }
        }

        if(!current_args.empty())
        {
            args.push_back(current_args);
        }

    return args;
}