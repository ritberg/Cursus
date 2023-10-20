/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:09:51 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/18 17:09:53 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {

public:

    PhoneBook(void);
    ~PhoneBook(void);
    class Contact {

    public:

        void    add_new(void);
        void    search(PhoneBook::Contact contacts[2], int i);
        void    replace(PhoneBook::Contact contacts[2]);

        char        name[512];
        char        surname[512];
        char        nickname[512];
        char        phone_numer[512];
        char        darkest_secret[512];
    
        Contact(void);
        ~Contact(void);
    };
};


#endif
