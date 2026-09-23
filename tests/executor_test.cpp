#include <iostream>

#include <executor.hpp>

int main()
{
    int result = execute({"true"});

    if (result == 0)
        std::cout << "[PASS] true exits with: " << result << '\n';
    else
        std::cout << "[FAIL] true exits with: " << result << '\n';

    result = execute({"false"});
    

    if (result == 1)
        std::cout << "[PASS] false exits with: " << result << '\n';
    else
        std::cout << "[FAIL] false exits with: " << result << '\n';

    
    result = execute({"real_command_trust_me"});
    

    if (result == 1)
        std::cout << "[PASS] unknown command exits with: " << result << '\n';
    else
        std::cout << "[FAIL] unknown command exits with: " << result << '\n';
}