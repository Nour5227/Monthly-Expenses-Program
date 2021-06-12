#pragma once
class Wallet
{
private:

	float cash_income;
	float credit_card;
	float debit_card;
public:
	

	Wallet();
	void SetCash(float);
	void SetCredit(float);
	float getCash();
	float getCredit();
	void setDebitCardAmount(float);
	float getDebitCardAmount();

	~Wallet();
};


