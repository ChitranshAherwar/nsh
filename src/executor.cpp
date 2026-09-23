#include "executor.hpp"

#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int execute(const std::vector<std::string>& args)
{
    std::vector<std::string> mutable_args = args;
    std::vector<char*> argv;

    for (auto& arg : mutable_args)
    {
        argv.push_back(arg.data());
    }

    argv.push_back(nullptr);

    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(argv[0], argv.data());
        std::cerr << "nsh: unknown command: " << argv[0] << '\n';

        _exit(1); // return 1; continues child process.
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status))
        {
            WEXITSTATUS(status);
        }

        return WEXITSTATUS(status);
    }
    else 
    {
        std::cout << "fork failde.\n";

        return 1;
    }

}