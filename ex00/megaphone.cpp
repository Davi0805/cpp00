#include <iostream>
#include <string>

std::string Trim(std::string str)
{
    size_t i = 0;
    while((str[i] == ' ' || str[i] == '\t') && i < str.length())
        i++;
    if (str[i] == ' ' || str[i] == '\t')
        str.erase(0, i);
    i = str.length() - 1;
    while((str[i] == ' ' || str[i] == '\t') && i > 0)
        i--;
    str = str.substr(0, i + 1);
    return (str);
}

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

    if (ac >= 2)
    {
        for(int i = 1; i < ac; i++)
        {
            _str = Trim(std::string(av[i]));
            _str = ToUpper(_str);
            if (i + 1 != ac)
                _str.append(" ");
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