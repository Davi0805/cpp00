/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:05:54 by davi              #+#    #+#             */
/*   Updated: 2025/01/05 12:45:02 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

#define RESET       "\033[0m"  
#define BLACK       "\033[30m" 
#define RED         "\033[31m" 
#define GREEN       "\033[32m" 
#define YELLOW      "\033[33m" 
#define BLUE        "\033[34m" 
#define MAGENTA     "\033[35m" 
#define CYAN        "\033[36m" 
#define WHITE       "\033[37m" 

Contacts::Contacts()
{
}

Contacts::~Contacts()
{
}

// Getters

std::string Contacts::get_first_name() const
{
    return this->_first_name;
}

std::string Contacts::get_last_name() const
{
    return this->_last_name;
}

std::string Contacts::get_nickname() const
{
    return this->_nickname;
}

std::string Contacts::get_phone_number() const
{
    return this->_phone_number;
}

std::string Contacts::get_secret() const
{
    return this->_secret;
}

// Setters
//!Atipico: Setter roda um prompt
void Contacts::set_first_name()
{
    std::string temp;
    std::cout << GREEN << "[CONTACT] " << RESET << "Enter your first name:" << std::endl;
    while (1)
    {
        std::cout << " > " << RESET;
        if (!std::getline(std::cin, temp))
        {
            std::cout << RED << "[ABORT]" << RESET << ": EOF detected!" << std::endl;
            std::cin.clear();
            return ;
        }
        if (temp.empty())
        {
            std::cout << RED << "[CONTACT] " << RESET << "First name cannot be empty!" << std::endl;
            continue ;
        }
        break;
    }
    this->_first_name = temp;
}
void Contacts::set_last_name()
{
    std::string temp;
    std::cout << GREEN << "[CONTACT] " << RESET << "Enter your last name:" << std::endl;
    while (1)
    {
        std::cout << " > " << RESET;
        if (!std::getline(std::cin, temp))
        {
            std::cout << RED << "[ABORT]" << RESET << ": EOF detected!" << std::endl;
            std::cin.clear();
            return ;
        }
        if (temp.empty())
        {
            std::cout << RED << "[CONTACT] " << RESET << "Last name cannot be empty!" << std::endl;
            continue ;
        }
        break;
    }
    this->_last_name = temp;
}

void Contacts::set_nickname()
{
    std::string temp;
    std::cout << GREEN << "[CONTACT] " << RESET << "Enter your nickname:" << std::endl;
    while (1)
    {
        std::cout << " > " << RESET;
        if (!std::getline(std::cin, temp))
        {
            std::cout << RED << "[ABORT]" << RESET << ": EOF detected!" << std::endl;
            std::cin.clear();
            return ;
        }
        if (temp.empty())
        {
            std::cout << RED << "[CONTACT] " << RESET << "Nickname cannot be empty!" << std::endl;
            continue ;
        }
        break;
    }
    this->_nickname = temp;
}

void Contacts::set_phone_number()
{
    std::string temp;
    std::cout << GREEN << "[CONTACT] " << RESET << "Enter your phoneNumber:" << std::endl;
    while (1)
    {
        std::cout << " > " << RESET;
        try
        {
            if (!std::getline(std::cin, temp))
                throw std::runtime_error("EOF detected!");
            if (temp.empty())
                throw std::runtime_error("Phone Number cannot be empty!");
            if (!IsOnlyDigits(temp))
                throw std::runtime_error("Only numbers are allowed in this field!");
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "[ERROR]" << RESET << ": " << e.what() << '\n';
            if (std::string(e.what()) == "EOF detected!")
            {
                std::cin.clear();
                return ;
            }
        }
        
    }
    this->_phone_number = temp;
}

void Contacts::set_secret()
{
    std::string temp;
    std::cout << GREEN << "[CONTACT] " << RESET << "Enter your deep secret:" << std::endl;
    while (1)
    {
        std::cout << " > " << RESET;
        if (!std::getline(std::cin, temp))
        {
            std::cout << RED << "[ABORT]" << RESET << ": EOF detected!" << std::endl;
            std::cin.clear();
            return ;
        }
        if (temp.empty())
        {
            std::cout << RED << "[CONTACT] " << RESET << "Deep secret cannot be empty!" << std::endl;
            continue ;
        }
        break;
    }
    this->_secret = temp;
}

std::string Contacts::FieldFormat(std::string str, size_t size) const
{
    if (str.length() > size)
    {
        str = str.substr(0, size - 1);
        str.append(".");
    }
    else if (str.length() < size)
    {
        std::string temp;
        size_t i = str.length();
        while (i++ < size)
            temp.append(" ");
        temp.append(str);
        return temp;
    }
    return str;
}

// Overload ou Override
/* std::ostream& operator<<(std::ostream& os, const Contacts& contact)
{
    os << "-------------------------------------------" << '\n';
    os << "|" << contact.FieldFormat("First name", 10) << '|' << contact.FieldFormat(contact.get_first_name(), 30) << '|' << '\n';
     os << "-------------------------------------------" << '\n';
    os << "|" << contact.FieldFormat("Last name", 10) << '|' << contact.FieldFormat(contact.get_last_name(), 30) << '|' << '\n';
     os << "-------------------------------------------" << '\n';
    os << "|" << contact.FieldFormat("Nickname", 10) << '|' << contact.FieldFormat(contact.get_nickname(), 30) << '|' << '\n';
     os << "-------------------------------------------" << '\n';
    os << "|" << contact.FieldFormat("Phone Number", 10) << '|' << contact.FieldFormat(contact.get_phone_number(), 30) << '|' << '\n';
     os << "-------------------------------------------" << '\n';
    os << "|" << contact.FieldFormat("Secret", 10) << '|' << contact.FieldFormat(contact.get_secret(), 30) << '|' << '\n';
     os << "-------------------------------------------" << '\n';
    return os;
} */

std::string Contacts::toString() const
{
    std::ostringstream os;
    os << "-------------------------------------------\n";
    os << "|" << FieldFormat("First name", 10) << '|' << FieldFormat(get_first_name(), 30) << "|\n";
    os << "-------------------------------------------\n";
    os << "|" << FieldFormat("Last name", 10) << '|' << FieldFormat(get_last_name(), 30) << "|\n";
    os << "-------------------------------------------\n";
    os << "|" << FieldFormat("Nickname", 10) << '|' << FieldFormat(get_nickname(), 30) << "|\n";
    os << "-------------------------------------------\n";
    os << "|" << FieldFormat("Phone Number", 10) << '|' << FieldFormat(get_phone_number(), 30) << "|\n";
    os << "-------------------------------------------\n";
    os << "|" << FieldFormat("Secret", 10) << '|' << FieldFormat(get_secret(), 30) << "|\n";
    os << "-------------------------------------------\n";
    
    return os.str();
}

bool Contacts::IsOnlyDigits(std::string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (std::isdigit(str[i]) == 0)
            return false;
    }
    return true;
}