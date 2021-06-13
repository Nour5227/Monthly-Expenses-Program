#include "expenses.h"
#include "Wallet.h"
# include<vector>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include<ctime>
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
	cout << "Enter your debit card amount : \n";
	float debitCardAmount;
	cin >> debitCardAmount;
	wallet.setDebitCardAmount(debitCardAmount);


}

void expenses::Expenses_Info()
{

	cout << "Enter how much is your income \n";
	cin >> Income;
	Wallet_Components();
	Make_Sure();
	
	cout << "Enter number of expenses : \n";
	cin >> Nexpenses;
	if (Nexpenses <= 0) {
		cout << "there is no expenses to track" << endl;
	}
	else
	{

		cout << "Enter The Month Number Of Expenses And The Year" << endl;
		cin >> month >> year;
		for (int i = 0; i < Nexpenses; i++)
		{
			cout << "Enter Name Of Expense " << i + 1 << "\n";
			cin.ignore();
			getline(cin, name);
			Name.push_back(name);
			cout << "Enter The Day Of The Expense In This Month \n";
			cin >> day;
			Date.push_back({ day,month,year });
			cout << "Enter Category Of Expense " << i + 1 << "\n";
			cin.ignore();
			getline(cin, category);
			Category.push_back(category);
			cout << "Enter Amount Of Expense " << i + 1 << "\n";
			cin >> amount;
			Amount.push_back(amount);
			cout << "cash or credit or debit ?\n";
			cin.ignore();
			getline(cin, choice);
			walletType.push_back(choice);


			if (choice.compare("cash") == 0 || choice.compare("CASH") == 0)
				total_paid_cash += amount;

			else if (choice.compare("credit") == 0 || choice.compare("CREDIT") == 0)
				total_paid_credit += amount;

			else if (choice.compare("debit") == 0 || choice.compare("DEBIT") == 0)
				total_paid_debit += amount;


		}
	}

	check_total_paid(total_paid_cash, total_paid_credit,total_paid_debit);

}

int expenses::getNexpenses()
{
	return Nexpenses;
}


void expenses::get_reminig_cash()
{
	
	remaining_Cash = wallet.getCash() - total_paid_cash;
	cout << "The remaining cash is : " << remaining_Cash << endl;
}
void expenses::get_reminig_credit()
{

	remaining_Credit = wallet.getCredit() - total_paid_credit;
	cout << "The remaining credit is : " << remaining_Credit << endl;
}
void expenses::get_reminig_debit()
{
	remaining_debit = wallet.getDebitCardAmount() - total_paid_debit;
	cout << "The remaining debit is : " << remaining_debit << endl;
}



void expenses::Make_Sure()
{


	while (true)
	{
		if (Income == wallet.getCash() + wallet.getCredit() + wallet.getDebitCardAmount())
			break;

		else
		{
			cout << "The total income should equal cash income + credit card icnome + debit card income " << endl;
			cout << " Enter cash , credit and debit in order \n";
			float Cash, Credit,debit;
			cin >> Cash;
			wallet.SetCash(Cash);
			cin >> Credit;
			wallet.SetCredit(Credit);
			cin >> debit;
			wallet.setDebitCardAmount(debit);

			if (Income == wallet.getCash() + wallet.getCredit() + wallet.getDebitCardAmount())
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
	expensedata.open("ExpenseData.csv", ios::app);
	expensedata << endl << "Total Income : " << Income << " " << "Cash Amount : " << wallet.getCash() << " " << "Credit Amount : " << wallet.getCredit() << " " << "Debit Amount : " << wallet.getDebitCardAmount() << "Remaining cash : " << remaining_Cash << " Remaining credit : " << remaining_Credit << " Remaining debit : " << remaining_debit;
	for (int i = 0; i < Nexpenses ; i++)
	{
		expensedata <<"Expense " << i+1 <<" : " <<"Name : "<< Name[i] << " " << "Category : " << Category[i] << " " << "Amount : " << Amount[i] << " " << "Wallet Type : " << walletType[i] <<" "<<"Date : " <<Date[i].day<< " /  " <<Date[i].month << " / " <<Date[i].year<<" ";

	}
}
void expenses::Filter_By_Amount(int R1, int R2)
{
	
		for (int i = 0; i <= Amount.size() - 1; i++) {
			if (Amount[i] >= R1 && Amount[i] <= R2) {
				filter_Amount.push(Amount[i]);
				filter_category.push(Category[i]);
				filter_Name.push(Name[i]);
				filter_Date.push(Date[i]);
				filter_walletType.push(walletType[i]);
			}
		}

		for (int i = 0; !filter_Amount.empty(); i++) {
			cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " << filter_Date.top().year << " Wallet Type : " << filter_walletType.top() << endl;
			filter_Name.pop();
			filter_Date.pop();
			filter_Amount.pop();
			filter_category.pop();
			filter_walletType.pop();
		}
	
	
}
void expenses::Filter_By_Category(string c)
{
	

	for (int i = 0; i <= Category.size() - 1; i++)
	{
		if (Category[i] == c) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
			filter_walletType.push(walletType[i]);
		}

	}
	for (int i = 0; !filter_Amount.empty(); i++)
	{
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " << filter_Date.top().year << " Wallet Type : " << filter_walletType.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
		filter_walletType.pop();

	}
}
void expenses::all()
{
	

	for (int i = 0; i <= Date.size() - 1; i++) {

		filter_Amount.push(Amount[i]);
		filter_category.push(Category[i]);
		filter_Name.push(Name[i]);
		filter_Date.push(Date[i]);
		filter_walletType.push(walletType[i]);

	}

	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " << filter_Date.top().year << " Wallet Type : " << filter_walletType.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
		filter_walletType.pop();
	}


}
void expenses::Filter_By_Date(int D)
{

	for (int i = 0; i <= Date.size() - 1; i++) {
		if (Date[i].day == D)
		{
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
			filter_walletType.push(walletType[i]);

		}
	}
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " << filter_Date.top().year << " Wallet Type : " << filter_walletType.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
		filter_walletType.pop();
	}

}
void expenses::Filter_by_Amount_Category(int l1, int l2, string s) {

	for (int i = 0; i <= Amount.size() - 1; i++) {
		if (Amount[i] >= l1 && Amount[i] <= l2 && Category[i] == s) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
			filter_walletType.push(walletType[i]);
		}
	}
	
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " << filter_Date.top().year << " Wallet Type : " << filter_walletType.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
		filter_walletType.pop();
	}



}
void expenses::Filter_by_Amount_Date(int n1, int n2, int d) {
	
	for (int i = 0; i <= Amount.size() - 1; i++) {
		if (Amount[i] >= n1 && Amount[i] <= n2 && Date[i].day == d) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
			filter_walletType.push(walletType[i]);
		}
	}
	
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " << filter_Date.top().year << " Wallet Type : " << filter_walletType.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
		filter_walletType.pop();
	}

}
void expenses::Filter_by_Category_Date(string s, int d) {
	
	for (int i = 0; i <= Category.size() - 1; i++) {
		if (Date[i].day == d && Category[i] == s) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
			filter_walletType.push(walletType[i]);
		}
	}
	
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " << filter_Date.top().year << " Wallet Type : " << filter_walletType.top() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
		filter_walletType.pop();
	}

}
void expenses::Filter_by_wallet(string wallet) {
	for (int i = 0; i < walletType.size(); i++) {
		if (walletType[i] == wallet) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
			filter_walletType.push(walletType[i]);
		}
	}
	for (int i = 0; !filter_walletType.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " <<filter_Date.top().year <<" Wallet Type : "<<filter_walletType.top()<< endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
		filter_walletType.pop();
	}

}
string expenses::getCategory() {
	string category;
	cout << "enter the name of the category" << endl;
	cin.ignore();
	getline(cin, category);

	return category;
}
int expenses::getDay()
{
	int Day;
	cout << "Enter the Day " << endl;
	cin >> Day;
	return Day;
}
float expenses::get_Minimum_Amount()
{
	int Minimum_Amount;
	cout << "enter minimum amount" << endl;
	cin >> Minimum_Amount;
	return Minimum_Amount;
}
float expenses::get_Maximum_Amount()
{
	int Maximum_Amount;
	cout << "enter maximum amount" << endl;
	cin >> Maximum_Amount;
	return Maximum_Amount;

}
void expenses::check_total_paid(float total_cash, float total_credit, float total_debit)
{
	if (total_cash > wallet.getCash() || total_credit > wallet.getCredit()|| total_debit > wallet.getDebitCardAmount())
	{
		cout << "The Total Paid Of Cash Or Credit or debit Is Greater Than Cash Or Credit Or debit \n ";
		cout << "Please, Fill you your expenses again :\n  ";
		Expenses_Info();
	}

}
void expenses::getRemainingForAllWallets() {
	get_reminig_cash();
	get_reminig_credit();
	get_reminig_debit();
}
string expenses::getWalletType() {
	cout << "enter wallet type" << endl;
	string walletType;
	cin >> walletType;
	return walletType;
}
expenses::~expenses()
{
}