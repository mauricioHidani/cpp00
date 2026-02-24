/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:59:30 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/24 20:05:09 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (size_t i = 1; i < static_cast<size_t>(argc); i++)
		for (size_t j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>(
				std::toupper(
					static_cast<unsigned char>(argv[i][j])
				)
			);
	std::cout << std::endl;

	return (0);
}
