/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:05:43 by davi              #+#    #+#             */
/*   Updated: 2025/01/05 12:33:43 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <csignal>

#define RESET       "\033[0m"  // Reset to default color
#define BLACK       "\033[30m" // Black
#define RED         "\033[31m" // Red
#define GREEN       "\033[32m" // Green

void sigint_handler(int signum)
{
    (void)signum;
    std::cout << GREEN << "[PHONEBOOK]" << RESET << " GoodBye!" << std::endl;
    exit(1);
}

int main(void)
{
    Phonebook phonebook;

    signal(SIGINT, sigint_handler);
    if (phonebook.Listen() == 1)
        return (0);
    return (0);
}