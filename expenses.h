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
	vector<string> walletType;
	Wallet wallet = Wallet();

public:

	expenses();
	void Wallet_Components();

	void Expenses_Info();
	void Make_Sure();
	void SaveDataInFile();
	void get_reminig_income();
	void Filter_By_Category(string); //this function views the expenses depending on user's category
	void Filter_By_Amount(int, int); //this function views expenses depending on user's money range
	~expenses();
};