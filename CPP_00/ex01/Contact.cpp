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
#include <iomanip>
#include <string>
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
    std::cout << "Enter a name" << std::endl;
    std::cin >> name;
    while (true) 
    {
        if (_check_name_surname(name) == false)
                std::cin >> name;
        else
            break;
    }
    std::cout << "Name: "<< name <<"" << std::endl;
    std::cout << "Enter a surname" << std::endl;
    std::cin >> surname;
    while (true) 
    {
        if (_check_name_surname(surname) == false)
                std::cin >> surname;
        else
            break;
    }
    std::cout << "Surname: "<< surname <<"" << std::endl;
    std::cout << "Enter a nickname" << std::endl;
    std::cin >> nickname;
    std::cout << "Nickname: "<< nickname <<"" << std::endl;
    std::cout << "Enter a phone number" << std::endl;
    std::cin >> phone_number;
    while (true) 
    {
        if (_check_phone_number(phone_number) == false)
            std::cin >> phone_number;
        else
            break;
    }
    std::cout << "Phone number: "<< phone_number <<"" << std::endl;
    std::cout << "Enter your darkest secret" << std::endl;
    std::cin >> darkest_secret;
    std::cout << "Darkest secret: "<< darkest_secret <<"" << std::endl;
}

bool    PhoneBook::Contact::_check_name_surname(std::string name_surname)
{
    for (int i = 0; i < name_surname.length(); i++)
    {
        if (!std::isalpha(name_surname[i]))
        {
            std::cout << "It must contain alphabetic characters" << std::endl;
            std::cin.clear();
            std::cout << "Try again:" << std::endl;
            return (false);
        }
    }
    return (true);
}

bool    PhoneBook::Contact::_check_phone_number(std::string phone_number)
{
    for (int i = 0; i < phone_number.length(); i++)
    {
        if (!std::isdigit(phone_number[i]))
        {
            std::cout << "It must be a digit!" << std::endl;
            std::cin.clear();
            std::cout << "Try again:" << std::endl;
            return (false);
        }
    }
    return (true);
}

void PhoneBook::Contact::search(PhoneBook::Contact contacts[8], int i)
{
    // creating std::string objects using the character arrays with the 10-char substrings
    std::string truncated_name = contacts[i].name;
    std::string truncated_surname = contacts[i].surname;
    std::string truncated_nickname = contacts[i].nickname;

    if (truncated_name.length() >= 10)
    {
        truncated_name = contacts[i].name.substr(0, 9);
        truncated_name.replace(9, 1, ".");
    }
    if (truncated_surname.length() >= 10)
    {
        truncated_surname = contacts[i].surname.substr(0, 9);
        truncated_surname.replace(9, 1, ".");
    }
    if (truncated_nickname.length() >= 10)
    {
        truncated_nickname = contacts[i].nickname.substr(0, 9);
        truncated_nickname.replace(9, 1, ".");
    }

    // setw(10) sets the width to 10 characters for the truncated_smth variables
    std::cout << std::setw(10) << std::right << i + 1 << "|" << truncated_name << "|"
            << truncated_surname << "|" << truncated_nickname << std::endl;
}

void    PhoneBook::Contact::search_index(PhoneBook::Contact contacts[8])
{
    int i;
    std::cout << "Enter a contact index" << std::endl;
    std::cin >> i;
    if (i > 0 && contacts[i - 1].name.empty())
        std::cout << "This contact doesn't exist yet" << std::endl;
    else if (i > 0 && i < 9)
    {
        std::cout << "Name: "<< contacts[i - 1].name <<"" << std::endl;
        std::cout << "Surname: "<< contacts[i - 1].surname <<"" << std::endl;
        std::cout << "Nickname: "<< contacts[i - 1].nickname <<"" << std::endl;
        std::cout << "Phone number: "<< contacts[i - 1].phone_number <<"" << std::endl;
        std::cout << "Darkest secret: "<< contacts[i - 1].darkest_secret <<"" << std::endl;
    }
    else
    {
        std::cout << "It must be a digit from 1 to 8!" << std::endl;
        std::cin.clear();
    }
}
