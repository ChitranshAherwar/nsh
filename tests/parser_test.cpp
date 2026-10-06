#include <iostream>
#include <vector>
#include <string>

#include "parser.hpp"

bool test_case(
    const std::string& name,
    const std::string& input,
    const std::vector<std::string>& expected
)
{
    ParsedCommand actual = tokenize(input);

    if (actual.args == expected)
    {
        std::cout << "[PASS] " << name << '\n';
        return true;
    }

    std::cout << "[FAIL] " << name << '\n';
    return false;

}

int main()
{
    bool all_passed = true;

    // test_case(name, input, expected)

    all_passed &= test_case(
        "empty input",
        "",
        std::vector<std::string>{}
    );

    all_passed &= test_case(
        "whitespace only",
        " ",
        std::vector<std::string>{}
    );

    all_passed &= test_case(
        "single command",
        "ls",
        std::vector<std::string>{"ls"}
    );

    all_passed &= test_case(
        "one argument",
        "ls -l",
        std::vector<std::string>{"ls", "-l"}
    );

    all_passed &= test_case(
        "multiple arguments",
        "ls -la /home",
        std::vector<std::string>{"ls", "-la", "/home"}
    );

    ParsedCommand actual = tokenize("echo hello > output.txt");

    if(
        actual.args == std::vector<std::string>{"echo", "hello"} &&
        actual.redirection == RedirectionType::Output &&
        actual.file == "output.txt")
    {
        std::cout << "[PASS] output redirection syntax\n";
    }
    else
    {
        std::cout << "[FAIL] output redirection syntax\n";
        all_passed = false;
    }

    return all_passed ? 0 : 1;
}