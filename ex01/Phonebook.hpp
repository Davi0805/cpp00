/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:05:49 by davi              #+#    #+#             */
/*   Updated: 2025/01/05 12:36:03 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contacts.hpp"
#include <cstdlib>

class Phonebook
{
private:
    Contacts contatos[8];
    int _index;

    // Commands
    void Add();
    void Search();

    // Getter
    int getIndex();

    // Utils
    std::string Trim(std::string str);
    void PrintHeader();
    void PrintBoundaries();
    void PrintTable();
    void FormatContacts(Contacts contato, int index);
    std::string Itoa(int nbr);
    std::string FieldFormatter(std::string str);
    bool IsOnlyDigits(std::string str);
    std::string ToUpper(std::string str);
public:
    Phonebook();
    ~Phonebook();

    // Setup
    int Listen();
};


#endif // PHONEBOOK_HPP
