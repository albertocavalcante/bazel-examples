#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string message = "Hello from hermetic C++ toolchain!";
    std::vector<std::string> platforms = {
        "linux_amd64",
        "linux_arm64",
        "darwin_arm64",
        "windows_amd64"};

    std::cout << message << std::endl;
    std::cout << "Supported platforms:" << std::endl;

    for (const auto &platform : platforms)
    {
        std::cout << "  - " << platform << std::endl;
    }

#ifdef __APPLE__
    std::cout << "Compiled for macOS" << std::endl;
#elif defined(__linux__)
    std::cout << "Compiled for Linux" << std::endl;
#elif defined(_WIN32)
    std::cout << "Compiled for Windows" << std::endl;
#else
    std::cout << "Compiled for an unknown platform" << std::endl;
#endif

    return 0;
}
