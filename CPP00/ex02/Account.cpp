/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:18:08 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 12:49:47 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
}

Account::~Account(void) {
	
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
	
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {

	_displayTimestamp();
	std::cout << " " << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
			  << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	if (deposit > 0)
	{
		_amount += deposit;
		_nbDeposits++;
		_totalNbDeposits++;
	}
	else if (deposit < 0)
		deposit = 0;
	_totalAmount += deposit;

	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;

}

bool Account::makeWithdrawal(int withdrawal) {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";

	if (withdrawal <= 0 || withdrawal > _amount)
	{
		withdrawal = 0;
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount(void) const {
	
	return _amount;
}

void Account::displayStatus(void) const {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {

	char s[20];
	std::time_t now;
	std::tm* tm;

	now = std::time(nullptr);
    tm = std::localtime(&now);
    std::strftime(s, sizeof(s), "[%Y%m%d_%H%M%S]", tm);
    std::cout << std::string(s);
}
