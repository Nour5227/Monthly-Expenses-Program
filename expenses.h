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

	float Income;
	struct date
	{
		//time_t now = time(0);
		//tm* ltm = localtime(&now);
		int day;
		int month;
	    int year ;
	};

	vector<date> Date;
	int Nexpenses;
	vector<float> Amount;
	vector<string> Category;
	vector<string> Name;
	vector<string> walletType;
	stack<string> filter_category; //taking a stack to save filtered expenses by categories
	stack<float> filter_Amount;  //taking a stack to save filtered expenses by amount
	stack<string> filter_Name;
	stack<date> filter_Date;
	/*queue<string> filter_category;
	queue<float> filter_Amount;
	queue<string> filter_Name;
	queue<date> filter_Date;*/
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
	void all();
	void Filter_By_Date(int);
	void Filter_by_Amount_Category(int, int, string);
	void Filter_by_Amount_Date(int, int, int);
	void Filter_by_Category_Date(string, int);
	float get_Minimum_Amount();
	float get_Maximum_Amount();
	int getDay();
	string getCategory();
	~expenses();
};