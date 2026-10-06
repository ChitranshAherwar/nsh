#include "parser.hpp"

#include <iostream>


ParsedCommand tokenize(const std::string& input)
{
    std::string current_args;
    std::vector<std::string> args;

    ParsedCommand command;


    for(int i = 0; i < input.size(); i++)
        {

            if(input[i] == ' ')
            {

                if(!current_args.empty())
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

    for(int i = 0; i < args.size(); i++)
    {
        if(args[i] == ">")
        {
            if(i + 1 < args.size())
            {
                command.redirection = RedirectionType::Output;
                command.file = args[i + 1];
                if(i + 2 < args.size())
                {
                    std::cerr << "syntax error: unexpected argument after output file.\n";
                    command.valid = false;
                    break;
                }
                break;
            }
            else
            {
                std::cerr << "syntax error: expected file after '>'\n";
                command.valid = false;
                break;
            }
            
        }
        else
        {
            command.args.push_back(args[i]);
        }
    }

    // command.args = args;
    return command;
}