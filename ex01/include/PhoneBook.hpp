/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:29:31 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/03 20:30:58 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

# define COL 10

class PhoneBook
{
private:
	Contact _contacts[8];
	size_t	_index;

protected:
	Contact	getContactByIndex(const size_t &index) const;

	void	printHeader();

	void	searchByIndex();
	void	searchByName();
	void	searchByLastname();
	void	searchByNickname();
	void	searchByContact();

public:
	PhoneBook();
	~PhoneBook();

	int		getIndex() const;
	Contact	*getContacts();
	void	addContact(const Contact &contact);
	void	addIndex();
	void	subtractIndex();

	void	print();
	void	search();
	void	add();
	void	exit() const;
};

#endif
