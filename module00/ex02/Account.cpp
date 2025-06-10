/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:44:52 by ekeinan           #+#    #+#             */
/*   Updated: 2025/03/31 18:48:30by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount= 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(): _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
}

Account::Account(int initial_deposit):  _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buffer[80];
	
	tstruct = *localtime(&now);
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", &tstruct);
	
	std::cout << "[" << buffer << "] ";
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";deposits:" << _nbDeposits << 
		";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout <<
		"accounts:" << _nbAccounts <<
		";total:" << _totalAmount <<
		";deposits:" << _totalNbDeposits << 
		";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}


void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";p_amount:" << _amount <<
		";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << 
		";amount:" << _amount <<
		";nb_deposits:" << ++_nbDeposits
	<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";p_amount:" << _amount <<
		";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << 
		withdrawal <<
		";amount:" << _amount <<
		";nb_withdrawals:" << ++_nbWithdrawals
	<< std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

int main()
{
	Account accounts[8] = {
		Account(42), Account(54), Account(957), Account(432),
		Account(1234), Account(0), Account(754), Account(16576)
	};
	
	int account_count = Account::getNbAccounts();

	Account::displayAccountsInfos();

	for (int i = 0; i < account_count; i++)
		accounts[i].displayStatus();
	
	const int deposits[] = { 5, 765, 564, 2, 87, 23, 9, 20 };
	for (int i = 0; i < account_count; i++)
		accounts[i].makeDeposit(deposits[i]);

	Account::displayAccountsInfos();
	
	for (int i = 0; i < account_count; i++)
		accounts[i].displayStatus();
	
	const int withdrawls[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
	for (int i = 0; i < account_count; i++)
		accounts[i].makeWithdrawal(withdrawls[i]);

	Account::displayAccountsInfos();
	
	for (int i = 0; i < account_count; i++)
		accounts[i].displayStatus();
	
	return 0;
}
