#include "expenses.h"
#include "Wallet.h"
# include<vector>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;



expenses::expenses()
{
	Income = 0;
	Nexpenses = 0;
	wallet = Wallet();

}

void expenses::Wallet_Components()
{
	cout << "Enter your net credit : \n";
	float credit;
	cin >> credit;
	wallet.SetCredit(credit);
	cout << "Enter your net cash : \n";
	float cash;
	cin >> cash;
	wallet.SetCash(cash);

}


void expenses::Expenses_Info()
{
	int day;
	string name, category;
	float amount;

	char choice;
	char choose;
	do {
		cout << "Enter how much is your income \n ";
		cin >> Income;
		Wallet_Components();
		Make_Sure();
		float reminig_cash = wallet.getCash();
		float reminig_credit = wallet.getCredit();
		cout << "Enter number of expenses : \n";
		cin >> Nexpenses;

		for (int i = 0; i < Nexpenses; i++)
		{
			cout << "Enter Name Of Expense " << i+1 << "\n ";
			cin >> name;
			Name.push_back(name);
			cout << "Enter The Day Of The Expense In This Month \n";
			cin >> day;
			Date.push_back({ day,5,2021 });
			cout << "Enter Category Of Expense " << i+1 << "\n ";
			cin >> category;
			Category.push_back(category);
			cout << "Enter Amount Of Expense " << i+1 << "\n";
			cin >> amount;
			Amount.push_back(amount);
			cout << "Cash (c) Or Credit (r) ?\n";
			cin >> choice;
			/*if (choice == 'c' || choice == 'C')
				reminig_cash = reminig_cash - amount;
			else if (choice == 'r' || choice == 'R')
				reminig_credit = reminig_credit - amount;*/

		}

		//get_reminig_income(reminig_cash, reminig_credit);
		cout << "Do you want to enter another expenses ? (y/n) \n  ";
		cin >> choose;

	} while (choose == 'y' || choose == 'Y');






}

//void expenses::get_reminig_income(float reminigCash, float  reminigCredit)
//{
//	cout << "The reminig income is :" << reminigCash + reminigCash << endl;
//}



void expenses::Make_Sure()
{


	while (true)
	{
		if (Income == wallet.getCash() + wallet.getCredit())
			break;

		else
		{
			cout << "The total income should equal cash income + credit card icnome" << endl;
			cout << " Enter cash and credit in order \n";
			float Cash, Credit;
			cin >> Cash;
			wallet.SetCash(Cash);
			cin >> Credit;
			wallet.SetCredit(Credit);


			if (Income == wallet.getCash() + wallet.getCredit())
			{
				cout << " success \n";
				break;
			}



		}
	}


}

expenses::~expenses()
{
}