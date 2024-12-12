#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "Invalid argument" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc ; i++)
    {
        std::fstream file(argv[i], std::ios::in);
        if (!file.is_open())
        {
            std::cout << argv[i] << ": ";
            std::cout << "Error on open" << std::endl;
            return errno;
        }

        std::string s;
        while (std::getline(file, s))
        {
            std::cout << s << std::endl;
        }

        file.close();
    }

    return 0;

}
