/* function time() returns the number of seconds passed since 00:00 01/01/1970; It always return a value;
it's argument is a pointer to a time_t object which stores the time.
Il valore di ritorno o si può assegnare direttamente ad un oggetto time_t con arg a NULL;
oppure si può passare l'oggetto, come referenza, come arg di time; In entrambi i casi si ha lo stesso risultato: ovvero che l'oggetto conterrà i secondi dal 1970; */
/* Function localtime() wants a pointer to an object timme_t and return a poointer obj of struct tm where, thanks to the obj and it's value we can access years, months ecc... with respective tm variables*/

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {
	std::time_t	obj_time;
	struct tm	*current_time;
	
	obj_time = time(NULL);
	current_time = localtime(&obj_time);
	std::cout << std::setfill('0') << '[' << current_time->tm_year + 1900 <<
		std::setw(2) << 1 + current_time->tm_mon <<
		std::setw(2) << current_time->tm_mday <<  '_' << 
		std::setw(2) << current_time->tm_hour <<
		std::setw(2) << current_time->tm_min <<
		std::setw(2) << current_time->tm_sec << "] ";
}

Account::Account( int initial_deposit ) {
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_displayTimestamp( );
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
}

Account::~Account( void ) {
	_displayTimestamp( );
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return ( _nbAccounts );
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit ) {
	_nbDeposits += 1;
	_amount += deposit;
	_displayTimestamp( );
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp( );
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal < _amount) {
		_nbWithdrawals += 1;
		_amount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
	} else
		return (checkAmount( ));
	return (1);
}

int	Account::checkAmount( void ) const {
	std::cout << "refused" << std::endl;
	return (0);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp( );
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp( );
	std::cout << "account:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
