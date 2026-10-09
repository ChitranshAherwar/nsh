#include <iostream>
#include <fstream>

#include "executor.hpp"

int main()
{
    ParsedCommand command;
    int result;

    command.args = {"ls"};
    result = execute(command);

    if(result == 0)
    {
        std::cout << "[PASS] single argument.\n";
    }
    else
    {
        std::cout << "[FAIL] single argument.\n";
    }

    command.args = {"ls", "-la"};
    result = execute(command);

    if(result == 0)
    {
        std::cout << "[PASS] multiple arguments.\n";
    }
    else
    {
        std::cout << "[FAIL] multiple arguments.\n";
    }

    command.args = {"fih"};
    result = execute(command);

    if(result != 0)
    {
        std::cout << "[PASS] unknown command.\n";
    }
    else
    {
        std::cout << "[FAIL] unknown command.\n";
    }

    command = ParsedCommand{};

    command.args = {"echo", "hello"};
    command.redirection = RedirectionType::Output;
    command.file = "output.txt";

    result = execute(command);

    if(result == 0)
    {
        std::ifstream myFile("output.txt", std::ios::in);

        if(myFile.is_open())
        {
            std::string line;
            myFile >> line;

            if(line == "hello")
            {
                std::cout << "[PASS] echo\n";
            }
            else
            {
                std::cout << "[FAIL] echo\n";
            }
        }
        else
        {
            std::cout << "[FAIL] echo\n";
        }
        myFile.close();
    }
    else
    {
        std::cout << "[FAIL] echo\n";
    }

    if(std::remove("output.txt") == 0)
    {
        std::cout << "File 'output.txt' deleted successfully.\n";
    }
    else
    {
        std::cout << "Error deleting file.\n";
    }
}
