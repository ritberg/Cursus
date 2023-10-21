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
    int     count = 0;
    char    buff[512];
    
    PhoneBook phonebook;
    PhoneBook::Contact contacts[2];  //change to 8

    while (true)
    {
        std::cin >> buff;
        if (strcmp(buff, "ADD") == 0 && count == 2) // change count to 8
        {
            contacts[1].add_new();
            count = 3; //change count to 9
        }
        else if (strcmp(buff, "ADD") == 0 && count < 2) //change to count < 8
        {
            for (int i = 0; i < 2; i++) //change to i < 8
            {
                contacts[i].add_new();
                count++;
            }
        }
        else if (strcmp(buff, "SEARCH") == 0)
        {
            for (int i = 0; i < 2; i++)        //change to i < 8
                contacts[i].search(contacts, i);
            contacts[2].search_index(contacts);
        }
        else if (strcmp(buff, "EXIT") == 0)
            return (0);
    }
    return (0);
}
