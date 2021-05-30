#pragma once
#include "Wallet.h"
# include<vector>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;


class expenses
{

	float Income;
	struct date
	{
		int day, month, year;
	};

	vector<date> Date;
	int Nexpenses;
	vector<float> Amount;
	vector<string> Category;
	vector<string> Name;
	Wallet wallet = Wallet();

public:

	expenses();
	void Wallet_Components();

	void Expenses_Info();
	//void get_reminig_income(float, float);
	void Make_Sure();

	~expenses();
};