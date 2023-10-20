/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:26:14 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/18 17:26:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::Contact::Contact(void)
{
    std::cout << "Constructor contact called" << std::endl;
    return;
}

PhoneBook::Contact::~Contact(void)
{
    std::cout << "Destructor contact called" << std::endl;
    return;
}

void    PhoneBook::Contact::add_new(void)
{
    {
        std::cout << "Enter a name" << std::endl;
        std::cin >> name;
        std::cout << "Name: "<< name <<"" << std::endl;
        std::cout << "Enter a surname" << std::endl;
        std::cin >> surname;
        std::cout << "Surname: "<< surname <<"" << std::endl;
        std::cout << "Enter a nickname" << std::endl;
        std::cin >> nickname;
        std::cout << "Name: "<< nickname <<"" << std::endl;
        std::cout << "Enter a phone number" << std::endl;
        std::cin >> phone_numer;
        std::cout << "Name: "<< phone_numer <<"" << std::endl;
        std::cout << "Enter your darkest secret" << std::endl;
        std::cin >> darkest_secret;
        std::cout << "Name: "<< darkest_secret <<"" << std::endl;
    }
}

void    PhoneBook::Contact::search(PhoneBook::Contact contacts[2], int i)
{
    std::cout << i + 1 << "|" << contacts[i].name \
        << "|" << contacts[i].surname << "|" << contacts[i].nickname << std::endl;
}
/*
void    PhoneBook::Contact::replace(PhoneBook::Contact contacts[2], int i)
{
    contacts[i].name = contacts[i - 1].name;
    contacts[i].surname = contacts[i - 1].surname;

}
*/
