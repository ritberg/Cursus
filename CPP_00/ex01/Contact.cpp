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
    this->bar();
    return;
}

PhoneBook::Contact::~Contact(void)
{
    std::cout << "Destructor contact called" << std::endl;
    return;
}

void    PhoneBook::Contact::bar(void)
{
    std::cout << "Function bar" << std::endl;
}