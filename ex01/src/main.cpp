/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:15:22 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/04 02:38:39 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	*phoneBook = new PhoneBook();
	std::string	input;

	while (true)
	{
		std::cout << "Enter some of the operations to perform an action";
		std::cout << "in PhoneBook:" << std::endl;
		std::cout << "ADD, SEARCH or EXIT" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, input))
			return (0);

		if (input.compare("ADD") == 0)
			phoneBook->add();
		else if (input.compare("SEARCH") == 0)
			phoneBook->search();
		else if (input.compare("EXIT") == 0)
		{
			phoneBook->exit();
			break ;
		}
	}
	delete phoneBook;
	return (0);
}
