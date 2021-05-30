#pragma once
class Wallet
{
private:

	float cash_income;
	float credit_card;

public:

	Wallet();
	void SetCash(float);
	void SetCredit(float);
	float getCash();
	float getCredit();
	~Wallet();
};


