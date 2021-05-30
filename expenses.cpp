#include "expenses.h"
#include "Wallet.h"
# include<vector>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
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

	string choice;
	//char choose;
	
		cout << "Enter how much is your income \n ";
		cin >> Income;
		Wallet_Components();
		Make_Sure();
		float reminig_cash = wallet.getCash();
		float reminig_credit = wallet.getCredit();
		cout << "Enter number of expenses : \n";
		cin >> Nexpenses;

		for (int i = 0 ; i < Nexpenses ; i++)
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
			cout << "Cash Or Credit ?\n";
			cin >> choice;
			walletType.push_back(choice);
			/*if (choice == 'c' || choice == 'C')
				reminig_cash = reminig_cash - amount;
			else if (choice == 'r' || choice == 'R')
				reminig_credit = reminig_credit - amount;*/

		}


		//get_reminig_income(reminig_cash, reminig_credit);
		/*cout << "Do you want to enter another expenses ? (y/n) \n  ";
		cin >> choose;

	} while (choose == 'y' || choose == 'Y');*/






}

void expenses::get_reminig_income()
{
	float paid = 0;
	for (int i = 0; i < Nexpenses ; i++)
	{
		paid += Amount[i];
	}

	cout << "The remaining income is : " << Income - paid << endl;
}



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
void expenses::SaveDataInFile()
{
	ofstream expensedata;
	expensedata.open("ExpenseData.txt", ios::app);
	expensedata << endl <<"Total Income : "<< Income << " " <<"Cash Amount : "<< wallet.getCash() << " " <<"Credit Amount : " << wallet.getCredit() << " ";
	for (int i = 0; i < Nexpenses ; i++)
	{
		expensedata <<"Expense " << i+1 <<" : " << Name[i] << " " << Category[i] << " " << Amount[i] << " " << walletType[i] <<" ";

	}
}
void expenses::Filter_By_Amount(int R1, int R2)
{
	//vector<float>::iterator it;
	stack<string> filter_category; //taking a stack to save filtered expenses by categories
	stack<float> filter_Amount;  //taking a stack to save filtered expenses by amount
	stack<string> filter_Name;
	stack<date> filter_Date;

	for (int i = 0; i <= Amount.size() - 1; i++) {
		if (i >= R1 && i <= R2) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
		}
	}

	for (int i = 0; i <= Amount.size() - 1; i++) {
		cout << filter_Name.top() << "\t" << filter_Date.top().day << "\t" << filter_category.top() << "\t" << filter_Amount.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
	}
}
void expenses::Filter_By_Category(string c)
{
	//vector<string>::iterator it;
	stack<string> filter_category; //taking a stack to save filtered expenses by categories
	stack<float> filter_Amount;  //taking a stack to save filtered expenses by amount
	stack<string> filter_Name;
	stack<date> filter_Date;

	for (int i = 0; i <= Category.size() - 1; i++)
	{
		if (Category[i] == c) {
			filter_category.push(Category[i]);
			filter_Amount.push(Amount[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
		}

	}
	for (int i = 0; i <= Category.size() - 1; i++) 
	{
		cout << filter_Name.top() << "\t" << filter_Date.top().day << "\t" << filter_category.top() << "\t" << filter_Amount.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_category.pop();
		filter_Amount.pop();

	}
}
expenses::~expenses()
{
}