/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:32:46 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/12 17:13:42 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
    Account::_displayTimestamp();
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_amount = 0;
    Account::_totalAmount += this->_amount;
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
    return ;
}

Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_amount = initial_deposit;
    Account::_totalAmount += this->_amount;
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
}

Account::~Account()
{
    Account::_nbAccounts--;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
    return ;
}

int	Account::getNbAccounts()
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
    return ;
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
    return ;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    this->_nbDeposits++;
    std::cout << ";deposit:" << deposit;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
    return ;
}

int     Account::checkAmount() const
{
    if (this->_amount < 0)
        return (0);
    return (1);
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    this->_amount -= withdrawal;
    if (!this->checkAmount())
    {
        this->_amount += withdrawal;
        std::cout << ";withdrawal:refused" << std::endl;
        return (0);
    }
    this->_nbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_withdrawals:" << this->_nbDeposits << std::endl;
    return (1);
}

void	Account::_displayTimestamp( void )
{
    time_t  timetoday;
    tm      *today;

    std::time(&timetoday);
    today = std::localtime(&timetoday);
    std::cout << "[";
    std::cout << today->tm_year + 1900;
    if (today->tm_mon < 10)
        std::cout << "0";
    std::cout << today->tm_mon;
    if (today->tm_mday < 10)
        std::cout << "0";
    std::cout << today->tm_mday;
    std::cout << "-";
    if (today->tm_hour < 10)
        std::cout << "0";
    std::cout << today->tm_hour;
    if (today->tm_min < 10)
        std::cout << "0";
    std::cout << today->tm_min;
    if (today->tm_sec < 10)
        std::cout << "0";
    std::cout << today->tm_sec;
    std::cout << "] ";
}




