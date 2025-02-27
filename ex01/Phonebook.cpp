/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:05:46 by davi              #+#    #+#             */
/*   Updated: 2025/01/05 12:32:28 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cctype>
#include <stdexcept>

// ANSI Color Macros

#define RESET       "\033[0m"  // Reset to default color
#define BLACK       "\033[30m" // Black
#define RED         "\033[31m" // Red
#define GREEN       "\033[32m" // Green
#define YELLOW      "\033[33m" // Yellow
#define BLUE        "\033[34m" // Blue
#define MAGENTA     "\033[35m" // Magenta
#define CYAN        "\033[36m" // Cyan
#define WHITE       "\033[37m" // White

Phonebook::Phonebook()
{
    this->_index = 0;
}

int Phonebook::Listen()
{
    std::string input;
    std::cout << GREEN << "[PHONEBOOK]" << RESET << " Welcome to Phonebook!" << std::endl;
    while(1)
    {
        try
        {
            std::cout << "Select commands: ADD, SEARCH, EXIT" << std::endl;
            if (!std::getline(std::cin, input))
                throw std::runtime_error("EOF detected!");
            input = ToUpper(input);
            if (input == "ADD")
                Add();
            else if (input == "SEARCH")
                Search();
            else if (input == "EXIT")
                break;
            else
                throw std::runtime_error("Invalid command!");
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "[ERROR]" << RESET << e.what() << '\n';
            if (std::string(e.what()) == "EOF detected!")
                return(1);
        }
        
    }
    return (0);
}

Phonebook::~Phonebook()
{
}

void Phonebook::Add()
{
        if (_index == 8)
            _index = 0;
        contatos[_index].set_first_name();
        contatos[_index].set_last_name();
        contatos[_index].set_nickname();
        contatos[_index].set_phone_number();
        contatos[_index].set_secret();
        std::cout << GREEN << "[PHONEBOOK]: Contact created!" << RESET << std::endl;
        _index++;
}

void Phonebook::Search()
{
    PrintTable();
    std::string input;
    std::cout << "Enter the index of the contact you want to search:" << '\n';
    while (1)
    {
        try
        {
            if (!std::getline(std::cin, input))
                throw std::runtime_error("EOF detected!");
            if (!IsOnlyDigits(input))
                throw std::runtime_error("Only digits are allowed!");
            int index = atoi(input.c_str());
            if (index >= 0 && index <= 7)
            {
                std::cout << contatos[index].toString() << std::endl;
                break;
            }
            throw std::runtime_error("Invalid index!!");
        }
        catch(const std::exception& e)
        {   
            std::cerr << RED << "[ERROR]" << RESET << ": " << e.what() << '\n';
            if (std::string(e.what()) == "EOF detected!")
                exit(1);
        }
        
    }
}

int Phonebook::getIndex()
{
    return this->_index;
}

std::string Phonebook::Trim(std::string str)
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

void Phonebook::PrintTable()
{
    PrintBoundaries();
    PrintHeader();
    PrintBoundaries();
    for(int i = 0; i < 8; i++)
    {
        FormatContacts(contatos[i], i);
        PrintBoundaries();
    }
}

void Phonebook::PrintHeader()
{
    std::cout << "|" << "     Index" << '|' << "First name" << '|' << " Last name" << '|' << "  Nickname" << "|\n";
}

void Phonebook::PrintBoundaries()
{
        std::string field = "----------";
        std::cout << field << field << field << field << "-----" << '\n';
}

std::string Phonebook::FieldFormatter(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9);
        str.append(".");
    }
    else if (str.length() < 10)
    {
        std::string temp;
        int i = str.length();
        while (i++ < 10)
            temp.append(" ");
        temp.append(str);
        return temp;
    }
    return str;
}

std::string Phonebook::Itoa(int nbr)
{
    std::ostringstream oss;
    oss << nbr;
    return oss.str();
}

void Phonebook::FormatContacts(Contacts contato, int index)
{
    std::string firstName = FieldFormatter(contato.get_first_name());
    std::string lastName = FieldFormatter(contato.get_last_name());
    std::string nickname = FieldFormatter(contato.get_nickname());

    std::cout << '|' << FieldFormatter(Itoa(index)) << '|' << firstName << '|' << lastName << '|' << nickname << '|' << '\n';

}

bool Phonebook::IsOnlyDigits(std::string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (std::isdigit(str[i]) == 0)
            return false;
    }
    return true;
}

std::string Phonebook::ToUpper(std::string str)
{
    std::string temp = str;
    for (size_t i = 0; i < str.length(); i++)\
    {
        temp[i] = toupper(temp[i]);
    }
    return (temp);
}

