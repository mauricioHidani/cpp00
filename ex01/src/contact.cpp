/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:04:10 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/03 08:33:50 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string &name, std::string &lastname, 
				 std::string &nickname, std::string &contact, 
				 std::string &secret) : _name(name), _lastname(lastname), 
				 _nickname(nickname), _contact(contact), _secret(secret)
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
	std::string	name = (
		_name.length() > col ? 
			_name.substr(0, col - 1) + "." : _name
	);
	std::string	lastname = (
		_lastname.length() > col ?
			_lastname.substr(0, col - 1) + ".": _lastname
	);
	std::string	contact = (
		_contact.length() > col ? 
			_contact.substr(0, col - 1) + "." : _contact
	);
	
	std::cout << index << "|";
	std::cout << std::setw(col) << name << "|";
	std::cout << std::setw(col) << lastname << "|";
	std::cout << std::setw(col) << contact;
	std::cout << std::endl;
}
