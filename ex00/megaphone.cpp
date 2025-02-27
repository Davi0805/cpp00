#include <iostream>
#include <string>

std::string ToUpper(std::string str)
{
    std::string temp = str;
    for (size_t i = 0; i < str.length(); i++)\
    {
        temp[i] = toupper(temp[i]);
    }
    return (temp);
}

std::string Megaphone(int ac, char **av)
{
    std::string _str;
    std::string result;

    (void)av;

    if (ac >= 2)
    {
        for(int i = 1; i < ac; i++)
        {
            _str = ToUpper(av[i]);
            result.append(_str);
        }
    }
    return result;
}

int main(int ac, char **av)
{
    if (ac > 1)
        std::cout << Megaphone(ac, av) << std::endl;
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}