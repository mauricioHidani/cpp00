/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:17:57 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/03 08:33:46 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phone Book has been destroyed" << std::endl;
}

int	PhoneBook::getIndex() const
{
	return (_index);
}

Contact	*PhoneBook::getContacts()
{
	return (_contacts);
}

Contact	PhoneBook::getContact(const size_t &index) const
{
	if (index > 8)
		return ;
	return (_contacts[index]);
}

void	PhoneBook::setIndex(const size_t &index)
{
	if (index > 8)
		return ;
	_index = index;
}

void	PhoneBook::addIndex()
{
	if (_index > 8)
		return ;
	_index++;
}

void	PhoneBook::subtractIndex()
{
	if (_index == 0)
		return ;
	_index--;
}

void	PhoneBook::printHeader()
{
	std::string	index = "index";
	std::string	name = "first name";
	std::string	lastname = "last name";
	std::string	nickname = "nickname";

	std::cout << std::setw(COL) << index << "|";
	std::cout << std::setw(COL) << name << "|";
	std::cout << std::setw(COL) << lastname << "|";
	std::cout << std::setw(COL) << nickname << std::endl;
}

void	PhoneBook::print()
{
	for (size_t	i = 0; i < 8; i++)
		_contacts[i].print(i, COL);
}

void	PhoneBook::search(const int index)
{
	if (index < 0 || index > 8)
	{
		printHeader();
		print();
		return ;
	}
	printHeader();
	_contacts[index].print(index, COL);
}

void	PhoneBook::search(const std::string nickname)
{
	for (size_t i = 0; i < 8; i++)
	{
		if (_contacts[i].getNickname() == nickname)
		{
			printHeader();
			_contacts[i].print(i, COL);
			return ;
		}
	}
	printHeader();
	print();
}

int	PhoneBook::add()
{
	Contact		contact;
	std::string	field;

	while (true)
	{
		if (contact.getName().empty())
		{
			std::cout << "Name: ";
			std::cin >> field;
			if (field.empty())
			{
				std::cout << "The name field is required!" << std::endl;
				continue ;
			}
			contact.setName(field);
		}
		else if (contact.getLastname().empty())
		{
			std::cout << "Lastname: ";
			std::cin >> field;
			if (field.empty())
			{
				std::cout << "The lastname field is required!" << std::endl;
				continue ;
			}
			contact.setLastname(field);
		}
		else if (contact.getNickname().empty())
		{
			std::cout << "Nickname: ";
			std::cin >> field;
			if (field.empty())
			{
				std::cout << "The nickname field is required!" << std::endl;
				continue ;
			}
			contact.setNickname(field);
		}
		else if (contact.getSecret().empty())
		{
			std::cout << "Secret: ";
			std::cin >> field;
			if (field.empty())
			{
				std::cout << "The secret field is required!" << std::endl;
				continue ;
			}
			contact.setSecret(field);
		}
		else if (contact.getContact().empty())
		{
			std::cout << "Contact: ";
			std::cin >> field;
			if (field.empty())
			{
				std::cout << "The contact field is required!" << std::endl;
				continue ;
			}
			contact.setContact(field);
			break ;
		}
	}
}

void	PhoneBook::exit() const
{
	std::cout << "Finish Phone Book" << std::endl;
}
