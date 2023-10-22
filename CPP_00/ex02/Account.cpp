/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:23:22 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/22 18:23:24 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
    _displayTimestamp();
	Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    std::cout << "index:" << _accountIndex << ";amount:" <<_amount
			<< ";created" << std::endl;
	return;
}

Account::~Account(void)
{
    _displayTimestamp();
	Account::_nbAccounts--;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
			<< ";closed" << std::endl;
	return;
}

int	Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
    time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";amount:" <<_amount
			<< ";deposits:" << _nbDeposits << ";withdrawals:"
            << _nbWithdrawals << std::endl;
	return;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits() << ";withdrawals:"
            << getNbWithdrawals() << std::endl;
	return;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount + deposit
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << withdrawal << ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
    return (true);
