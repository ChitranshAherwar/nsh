#include "executor.hpp"

#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <fcntl.h>
#include <cerrno>
#include <cstring>

int execute(const ParsedCommand& command)
{
    std::vector<std::string> mutable_args = command.args;
    std::vector<char*> argv;

    for(auto& arg : mutable_args)
    {
        argv.push_back(arg.data());
    }

    argv.push_back(nullptr);

    pid_t pid = fork();

    if(pid == 0)
    {
        if(command.redirection == RedirectionType::Output)
        {
            int fd = open(command.file.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);

            if(fd == -1)
            {
                std::cerr << "nsh: " << command.file << ": " << strerror(errno) << '\n';
                _exit(1);
            }

            dup2(fd, STDOUT_FILENO);
            close(fd);
        }

        execvp(argv[0], argv.data());
        std::cerr << "nsh: unknown command: " << argv[0] << '\n';

        _exit(1); // return 1; continues child process.
    }
    else if(pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        
        if(WIFEXITED(status))
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