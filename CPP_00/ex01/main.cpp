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
    int count = 0;
    
    PhoneBook phonebook;
    PhoneBook::Contact contacts[2];

    while (true)
    {
        std::cin >> buff;
      //  if (strcmp(buff, "ADD") == 0 && count >= 2)
       //     contacts[2].replace(contacts);
        if (strcmp(buff, "ADD") == 0 && count < 2)
        {
            for (int i = 0; i < 2; i++)
            {
                contacts[i].add_new();
                count++;
            }
        }
        else if (strcmp(buff, "SEARCH") == 0)
        {
            for (int i = 0; i < 2; i++)
                contacts[i].search(contacts, i);
        }
        else if (strcmp(buff, "EXIT") == 0)
            return (0);
    }
    return (0);
}
