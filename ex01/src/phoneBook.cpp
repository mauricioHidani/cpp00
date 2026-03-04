/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 08:17:57 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/04 11:30:35 by mhidani          ###   ########.fr       */
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

void	PhoneBook::addContact(const Contact &contact)
{
	if (_index >= 8)
		_contacts[0] = contact;
	_contacts[_index] = contact;
}

void	PhoneBook::addIndex()
{
	if (_index >= 7)
	{
		_index = 7;
		return ;
	}
	_index++;
}

void	PhoneBook::subtractIndex()
{
	if (_index == 0)
		return ;
	_index--;
}

Contact	PhoneBook::getContactByIndex(const size_t &index) const
{
	if (index > 8)
		throw std::out_of_range("Invalid Phone Book index.");
	return (_contacts[index]);
}

void	PhoneBook::printHeader()
{
	std::cout << std::endl;
	std::cout << std::setw(COL) << "index" << "|";
	std::cout << std::setw(COL) << "name" << "|";
	std::cout << std::setw(COL) << "lastname" << "|";
	std::cout << std::setw(COL) << "nickname" << "|";
	std::cout << std::setw(COL) << "contact" << std::endl;
}

void	PhoneBook::searchByIndex()
{
	std::string	input;
	size_t		index;
	int			target;

	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.empty())
	{
		printHeader();
		for (size_t i = 0; i < 8; i++)
			_contacts[i].print(i, COL);
		return ;
	}
	target = std::atoi(input.c_str());
	if (target < 0 || target > 8)
	{
		std::cout << "Invalid input!" << std::endl;
		return ;
	}
	printHeader();
	index = static_cast<size_t>(target) - 1;
	_contacts[index].print(index, COL);
}

void	PhoneBook::searchByName()
{
	std::string	input;

	std::cout << "Name: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.empty())
	{
		printHeader();
		for (size_t i = 0; i < 8; i++)
			_contacts[i].print(i, COL);
		return ;
	}
	printHeader();
	for (size_t i = 0; i < 8; i++)
		if (_contacts[i].getName().compare(input) == 0)
			_contacts[i].print(i, COL);
}

void	PhoneBook::searchByLastname()
{
	std::string	input;

	std::cout << "Lastname: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.empty())
	{
		printHeader();
		for (size_t i = 0; i < 8; i++)
			_contacts[i].print(i, COL);
		return ;
	}
	printHeader();
	for (size_t i = 0; i < 8; i++)
		if (_contacts[i].getLastname().compare(input) == 0)
			_contacts[i].print(i, COL);
}

void	PhoneBook::searchByNickname()
{
	std::string	input;

	std::cout << "Nickname: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.empty())
	{
		printHeader();
		for (size_t i = 0; i < 8; i++)
			_contacts[i].print(i, COL);
		return ;
	}
	printHeader();
	for (size_t i = 0; i < 8; i++)
		if (_contacts[i].getNickname().compare(input) == 0)
			_contacts[i].print(i, COL);
}

void	PhoneBook::searchByContact()
{
	std::string	input;

	std::cout << "Contact: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.empty())
	{
		printHeader();
		for (size_t i = 0; i < 8; i++)
			_contacts[i].print(i, COL);
		return ;
	}
	printHeader();
	for (size_t i = 0; i < 8; i++)
		if (_contacts[i].getContact().compare(input) == 0)
			_contacts[i].print(i, COL);
}


void	PhoneBook::search()
{
	std::string	input;

	std::cout << "Enter the search type by typing your choice:" << std::endl;
	std::cout << "- INDEX" << std::endl;
	std::cout << "- NAME" << std::endl;
	std::cout << "- LASTNAME" << std::endl;
	std::cout << "- NICKNAME" << std::endl;
	std::cout << "- CONTACT" << std::endl;
	std::cout << "> ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.empty())
	{
		printHeader();
		for (size_t i = 0; i < 8; i++)
			_contacts[i].print(i, COL);
		return ;
	}
	if (input.compare("INDEX") == 0)
		searchByIndex();
	else if (input.compare("NAME") == 0)
		searchByName();
	else if (input.compare("LASTNAME") == 0)
		searchByLastname();
	else if (input.compare("NICKNAME") == 0)
		searchByNickname();
	else if (input.compare("CONTACT") == 0)
		searchByContact();
}

void	PhoneBook::add()
{
	std::string	cs[5] = {"Name", "Lastname", "Nickname", "Contact", "Secret"};
	std::string	input = "";
	size_t		idx = _index == 7 ? 0 : _index;
	size_t		i = 0;

	while (i < 5)
	{
		std::cout << cs[i] << ": ";
		if (!std::getline(std::cin, input))
			continue ;
		if (input.empty())
		{
			std::cout << cs[i] << " field is required!" << std::endl;
			continue ;
		}
		switch (i)
		{
			case 0:	_contacts[idx].setName(input);		break;
			case 1:	_contacts[idx].setLastname(input);	break;
			case 2: _contacts[idx].setNickname(input);	break;
			case 3: _contacts[idx].setContact(input);	break;
			case 4: _contacts[idx].setSecret(input);	break;
			default: 									break;
		}
		i++;
	}
	addIndex();
}

void	PhoneBook::exit() const
{
	std::cout << "Finish Phone Book" << std::endl;
}
