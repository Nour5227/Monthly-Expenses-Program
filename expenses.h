#pragma once
#include "Wallet.h"
# include<vector>
#include <ctime>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;


class expenses
{

	struct date
	{
		int day;
		int month;
	    int year ;
	};
	float Income;
	int day, month, year;
	string name, category;
	float amount ;
	string choice;
	int Nexpenses;
	float total_paid_cash = 0;
	float total_paid_credit = 0;
	float total_paid_debit = 0;


	float remaining_Cash;
	float remaining_Credit;
	float remaining_debit;


	vector<date> Date;
	vector<float> Amount;
	vector<string> Category;
	vector<string> Name;
	vector<string> walletType;
	stack<string> filter_category; //taking a stack to save filtered expenses by categories
	stack<float> filter_Amount;  //taking a stack to save filtered expenses by amount
	stack<string> filter_Name;
	stack<date> filter_Date;
	stack<string>filter_walletType;
	Wallet wallet = Wallet();


public:

	expenses();
	void Wallet_Components();
	void Expenses_Info();
	int getNexpenses();
	void Make_Sure();
	void SaveDataInFile();
	void get_reminig_cash();
	void get_reminig_credit();
	void get_reminig_debit();

	void getRemainingForAllWallets();
	void Filter_By_Category(string); //this function views the expenses depending on user's category
	void Filter_By_Amount(int, int); //this function views expenses depending on user's money range
	void all();
	void Filter_By_Date(int);
	void Filter_by_Amount_Category(int, int, string);
	void Filter_by_Amount_Date(int, int, int);
	void Filter_by_Category_Date(string, int);
	void Filter_by_wallet(string);
	float get_Minimum_Amount();
	float get_Maximum_Amount();
	int getDay();
	string getCategory();
	string getWalletType();
	void check_total_paid(float total_cash, float total_credit, float total_debit);
	~expenses();
};