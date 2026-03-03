/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:53:57 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/28 09:19:29 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	std::string	_name;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_contact;
	std::string	_secret;

public:
	Contact();
	Contact(std::string &name, std::string &lastname, std::string &nickname, 
			std::string &contact, std::string &secret);
	~Contact();

	std::string	getName() const;
	std::string	getLastname() const;
	std::string	getNickname() const;
	std::string	getContact() const;
	std::string	getSecret() const;
	void		setName(const std::string &name);
	void		setLastname(const std::string &lastname);
	void		setNickname(const std::string &nickname);
	void		setContact(const std::string &contact);
	void		setSecret(const std::string &secret);
	void		print(const size_t index, const size_t col);
};

#endif
