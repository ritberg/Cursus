/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:08:31 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/18 17:08:33 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"

int main()
{
    char    buff[512];
 
    PhoneBook   phonebook;

    std::cin >> buff;
    if (strcmp(buff, "ADD") == 0)
        PhoneBook::Contact     contact1;

 
 //   PhoneBook::Contact     contact2;
 //   PhoneBook::Contact     contact3;
 //   PhoneBook::Contact     contact4;

  

    return (0);
}
