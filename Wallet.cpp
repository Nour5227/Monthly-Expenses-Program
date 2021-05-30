#include "Wallet.h"
Wallet::Wallet()
{
	cash_income = 0;
	credit_card = 0;
}

void Wallet::SetCash(float cash)
{
	cash_income = cash;
}

void Wallet::SetCredit(float credit)
{
	credit_card = credit;
}

float Wallet::getCash()
{
	return cash_income;
}

float Wallet::getCredit()
{
	return credit_card;
}


Wallet::~Wallet()
{
}