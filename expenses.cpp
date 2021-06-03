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

}

void expenses::Expenses_Info()
{

	int day;
	string name, category;
	float amount;
	float total_paid_cash = 0;
	float total_paid_credit = 0;
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

	for (int i = 0; i < Nexpenses; i++)
	{
		cout << "Enter Name Of Expense " << i + 1 << "\n ";
		cin.ignore();
		getline(cin, name);
		Name.push_back(name);
		cout << "Enter The Day Of The Expense In This Month \n";
		cin >> day;
		Date.push_back({ day,5,2021 });
		cout << "Enter Category Of Expense " << i + 1 << "\n ";
		cin.ignore();
		getline(cin, category);
		Category.push_back(category);
		cout << "Enter Amount Of Expense " << i + 1 << "\n";
		cin >> amount;
		Amount.push_back(amount);
		cout << "Cash Or Credit ?\n";
		cin.ignore();
		getline(cin, choice);
		walletType.push_back(choice);


		if (choice.compare("cash") == 0 || choice.compare("CASH") == 0)
			total_paid_cash += amount;

		else if (choice.compare("credit") == 0 || choice.compare("CREDIT") == 0)
			total_paid_credit += amount;

	}

	check_total_paid(total_paid_cash, total_paid_credit);

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
		expensedata <<"Expense " << i+1 <<" : " << Name[i] << " " << Category[i] << " " << Amount[i] << " " << walletType[i] <<" "
			<<" "<<"Date :" <<Date[i].day<< " /  " <<Date[i].month << " / " <<Date[i].year<<" ";

	}
}
void expenses::Filter_By_Amount(int R1, int R2)
{
	//vector<float>::iterator it;
	//stack<string> filter_category; //taking a stack to save filtered expenses by categories
	//stack<float> filter_Amount;  //taking a stack to save filtered expenses by amount
	//stack<string> filter_Name;
	//stack<date> filter_Date;
	
		for (int i = 0; i <= Amount.size() - 1; i++) {
			if (Amount[i] >= R1 && Amount[i] <= R2) {
				filter_Amount.push(Amount[i]);
				filter_category.push(Category[i]);
				filter_Name.push(Name[i]);
				filter_Date.push(Date[i]);
			}
		}

		for (int i = 0; !filter_Amount.empty(); i++) {
			cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " <<
				filter_Date.top().year << endl;
			filter_Name.pop();
			filter_Date.pop();
			filter_Amount.pop();
			filter_category.pop();
		}
	
	
}
void expenses::Filter_By_Category(string c)
{
	////vector<string>::iterator it;
	//stack<string> filter_category; //taking a stack to save filtered expenses by categories
	//stack<float> filter_Amount;  //taking a stack to save filtered expenses by amount
	//stack<string> filter_Name;
	//stack<date> filter_Date;

	for (int i = 0; i <= Category.size() - 1; i++)
	{
		if (Category[i] == c) {
			filter_category.push(Category[i]);
			filter_Amount.push(Amount[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
		}

	}
	for (int i = 0; !filter_Amount.empty(); i++)
	{
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " <<
			filter_Date.top().year << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_category.pop();
		filter_Amount.pop();

	}
}
void expenses::all()
{
	/*stack<string> filter_category;
	stack<float> filter_Amount;
	stack<string> filter_Name;
	stack<date> filter_Date;*/

	for (int i = 0; i <= Date.size() - 1; i++) {

		filter_Date.push(Date[i]);
		filter_Amount.push(Amount[i]);
		filter_category.push(Category[i]);
		filter_Name.push(Name[i]);

	}

	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " <<
			filter_Date.top().year << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
	}


}
void expenses::Filter_By_Date(int D)
{
	/*stack<string> filter_category;
	stack<float> filter_Amount;
	stack<string> filter_Name;
	stack<date> filter_Date;*/

	for (int i = 0; i <= Date.size() - 1; i++) {
		if (Date[i].day == D)
		{
			filter_Date.push(Date[i]);
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);

		}
	}
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " <<
			filter_Date.top().year << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
	}

}
void expenses::Filter_by_Amount_Category(int l1, int l2, string s) {
	/*queue<string> filter_category;
	queue<float> filter_Amount;
	queue<string> filter_Name;
	queue<date> filter_Date;*/

	for (int i = 0; i <= Amount.size() - 1; i++) {
		if (Amount[i] >= l1 && Amount[i] <= l2 && Category[i] == s) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
		}
	}
	/*for (int i = 0; !filter_Amount.empty(); i++)
	{
		cout << "Name : " << filter_Name.front() << "\t" << "Day : " << filter_Date.front().day << "\t" << "Category : " << filter_category.front() << "\t" << "Amount : " << filter_Amount.front() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_category.pop();
		filter_Amount.pop();

	}*/
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" <<"Date : "<< filter_Date.top().day<<" / "<< filter_Date.top().month << " / " <<
			filter_Date.top().year << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
	}



}
void expenses::Filter_by_Amount_Date(int n1, int n2, int d) {
	/*queue<string> filter_category;
	queue<float> filter_Amount;
	queue<string> filter_Name;
	queue<date> filter_Date;*/
	for (int i = 0; i <= Amount.size() - 1; i++) {
		if (Amount[i] >= n1 && Amount[i] <= n2 && Date[i].day == d) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
		}
	}
	/*for (int i = 0; !filter_Amount.empty(); i++)
	{
		cout << "Name : " << filter_Name.front() << "\t" << "Day : " << filter_Date.front().day << "\t" << "Category : " << filter_category.front() << "\t" << "Amount : " << filter_Amount.front() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_category.pop();
		filter_Amount.pop();

	}*/
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " <<
			filter_Date.top().year << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
	}

}
void expenses::Filter_by_Category_Date(string s, int d) {
	/*queue<string> filter_category;
	queue<float> filter_Amount;
	queue<string> filter_Name;
	queue<date> filter_Date;*/
	for (int i = 0; i <= Category.size() - 1; i++) {
		if (Date[i].day == d && Category[i] == s) {
			filter_Amount.push(Amount[i]);
			filter_category.push(Category[i]);
			filter_Name.push(Name[i]);
			filter_Date.push(Date[i]);
		}
	}
	/*for (int i = 0; !filter_category.empty(); i++)
	{
		cout << "Name : " << filter_Name.front() << "\t" << "Day : " << filter_Date.front().day << "\t" << "Category : " << filter_category.front() << "\t" << "Amount : " << filter_Amount.front() << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_category.pop();
		filter_Amount.pop();

	}*/
	for (int i = 0; !filter_Amount.empty(); i++) {
		cout << "Name : " << filter_Name.top() << "\t" << "Category : " << filter_category.top() << "\t" << "Amount : " << filter_Amount.top() << "\t" << "Date : " << filter_Date.top().day << " / " << filter_Date.top().month << " / " <<
			filter_Date.top().year << endl;
		filter_Name.pop();
		filter_Date.pop();
		filter_Amount.pop();
		filter_category.pop();
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
void expenses::check_total_paid(float total_cash, float total_credit)
{
	if (total_cash > wallet.getCash() || total_credit > wallet.getCredit())
	{
		cout << "The Total Paid Of Cash Or Credit Is Greater Than Cash O Credit \n ";
		cout << "Please, Fill you your expenses again :\n  ";
		Expenses_Info();
	}

}
expenses::~expenses()
{
}