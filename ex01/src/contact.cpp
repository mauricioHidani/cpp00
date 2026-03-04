/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:04:10 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/04 11:30:57 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
	std::cout << "Contact has been destroyed" << std::endl;
}

std::string	Contact::getName() const
{
	return (_name);
}

std::string	Contact::getLastname() const
{
	return (_lastname);
}

std::string Contact::getNickname() const
{
	return (_nickname);
}

std::string	Contact::getContact() const
{
	return (_contact);
}

std::string	Contact::getSecret() const
{
	return (_secret);
}

void	Contact::setName(const std::string &name)
{
	_name = name;
}

void	Contact::setLastname(const std::string &lastname)
{
	_lastname = lastname;
}

void	Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void	Contact::setContact(const std::string &contact)
{
	_contact = contact;
}


void	Contact::setSecret(const std::string &secret)
{
	_secret = secret;
}

void	Contact::print(const size_t index, const size_t col)
{
	std::cout << std::setw(col) << index + 1 << "|";
	std::cout << std::setw(col) << limitColumn(_name, col) << "|";
	std::cout << std::setw(col) << limitColumn(_lastname, col) << "|";
	std::cout << std::setw(col) << limitColumn(_nickname, col) << "|";
	std::cout << std::setw(col) << limitColumn(_contact, col);
	std::cout << std::endl;
}

std::string	Contact::limitColumn(std::string str, const size_t col)
{
	if (str.length() > col)
		return (str.substr(0, col - 1) + ".");
	return (str);
}
