#include <iostream>
#include "expenses.h"
#include "Wallet.h"


using namespace std;
int main()
{
	char answer;

	cout << "---------------------: Welcome To Monthly Expenses Tracking App :---------------------\n" << endl;
	do {
		expenses EXPENSES = expenses();
		EXPENSES.Expenses_Info();

		while (true) {

			cout << " \n How do you want to view your expenses?" << endl
				<< "1.view all \n2.view by date \n3.view by category \n4.view by amount \n5.view by multiple\n or press 0 to exit\n";
			int filter_choice;
			cin >> filter_choice;

			if (filter_choice == 3) {
				string c;
				cout << "enter the name of the category" << endl;
				cin >> c;
				EXPENSES.Filter_By_Category(c);


			}

			if (filter_choice == 4) {
				int R1, R2;
				cout << "enter minimum amount" << endl;
				cin >> R1;
				cout << "enter maximum amount" << endl;
				cin >> R2;
				EXPENSES.Filter_By_Amount(R1, R2);
			}

			if (filter_choice == 0) {
				break;
			}
		}
		EXPENSES.SaveDataInFile();
		EXPENSES.get_reminig_income();
		cout << "Do You Want To Enter Another Expenses ? (y/n)" << endl;
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}