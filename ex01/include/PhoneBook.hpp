/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:29:31 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/03 07:12:01 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iomanip>
# include "Contact.hpp"

# define COL 10

class PhoneBook
{
private:
	Contact _contacts[8];
	size_t	_index;

public:
	PhoneBook();
	~PhoneBook();

	int		getIndex() const;
	Contact	*getContacts();
	Contact	getContact(const size_t &index) const;
	void	setIndex(const size_t &index);
	void	addIndex();
	void	subtractIndex();
	
	void	printHeader();
	void	print();
	void	search(const int index);
	void	search(const std::string nickname);
	int		add();
	void	exit() const;
};

#endif
