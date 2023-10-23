/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:08:31 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/23 17:01:29 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"

int main()
{
    std::string buff;
    int         count = 0;
    int         flag = 0;
    
    PhoneBook           phonebook;
    PhoneBook::Contact  contacts[8];

    while (true)
    {
        std::cin >> buff;
        if (buff == "ADD" && count == 8 && flag == 0)
        {
            contacts[0].add_new();
            flag = 1;
        }
        else if (buff == "ADD" && count < 8)
        {
            contacts[count].add_new();
            count++;
        }
        else if (buff == "SEARCH")
        {
            for (int i = 0; i < count; i++)       
                contacts[i].search(contacts, i);
            contacts[count].search_index(contacts);
        }
        else if (buff == "EXIT")
            return (0);
    }
    return (0);
}
