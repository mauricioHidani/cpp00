/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:16:57 by mhidani           #+#    #+#             */
/*   Updated: 2026/03/05 22:28:25 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_displayTimestamp();

	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	
	std::cout	<< "index:"		<< _accountIndex	<< ";";
	std::cout	<< "amount:"	<< _amount			<< ";";
	std::cout	<< "created"	<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();

	_nbAccounts--;

	std::cout	<< "index:"		<< _accountIndex	<< ";";
	std::cout	<< "amount:"	<< _amount			<< ";";
	std::cout	<< "closed"		<< std::endl;

}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;

	_displayTimestamp();
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout	<< "index:"			<< _accountIndex	<< ";";
	std::cout	<< "p_amount:"		<< p_amount			<< ";";
	std::cout	<< "deposit:"		<< deposit			<< ";";
	std::cout	<< "amount:"		<< _amount			<< ";";
	std::cout	<< "nb_deposits:"	<< _nbDeposits		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex	<< ";";
	std::cout	<< "p_amount:"	<< _amount			<< ";";

	if (withdrawal > _amount)
	{
		std::cout	<< "withdrawal:refused"	<< std::endl;
		return (false);
	}
	
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout	<< "withdrawal:"		<< withdrawal		<< ";";
	std::cout	<< "amount:"			<< _amount			<< ";";
	std::cout	<< "nb_withdrawals:"	<< _nbWithdrawals	<< std::endl;
	return (true);
}

void	Account::_displayTimestamp( void )
{
	char			buffer[20];
	std::time_t		now = std::time(NULL);
	struct std::tm	*local = std::localtime(&now);

	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local);
	std::cout	<< "["	<< buffer	<< "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:"		<< _nbAccounts			<< ";";
	std::cout	<< "total:"			<< _totalAmount			<< ";";
	std::cout	<< "deposits:"		<< _totalNbDeposits		<< ";";
	std::cout	<< "withdrawals:"	<< _totalNbWithdrawals	<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:"			<< _accountIndex	<< ";";
	std::cout	<< "amount:"		<< _amount			<< ";";
	std::cout	<< "deposits:"		<< _nbDeposits		<< ";";
	std::cout	<< "withdrawals:"	<< _nbWithdrawals	<< std::endl;
}
