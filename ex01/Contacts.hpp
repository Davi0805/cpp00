/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:05:51 by davi              #+#    #+#             */
/*   Updated: 2025/01/05 12:42:50 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class Contacts
{
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _secret;
public:
    Contacts();
    ~Contacts();

    // Overload ou Override
    /* friend std::ostream& operator<<(std::ostream& os, const Contacts &contact); // Cout override */


    // Getter
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_secret() const;

    // Setter
    void set_first_name();
    void set_last_name();
    void set_nickname();
    void set_phone_number();
    void set_secret();

    //UTILS
    std::string FieldFormat(std::string str, size_t size) const;
    bool IsOnlyDigits(std::string str);
    std::string toString() const;
};


#endif // !CONTACTS_HPP