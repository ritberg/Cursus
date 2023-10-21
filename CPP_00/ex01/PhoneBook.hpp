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
        void    search(PhoneBook::Contact contacts[2], int i); //change to 8
        void    search_index(PhoneBook::Contact contacts[2]);  //change to 8

        std::string name;
        std::string surname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

      //  int contact_ind;
    
        Contact(void);
        ~Contact(void);
    };
};


#endif
