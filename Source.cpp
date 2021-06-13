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
		

			while (true)
			{
				if (EXPENSES.getNexpenses() <= 0) {
							break;
				}
				else
				{


					cout << " \n How do you want to view your expenses?" << endl
						<< "1.view all \n2.view by date \n3.view by category \n4.view by amount \n5.view by multiple\n6.view by wallet \n7.view remaining cash\n8.view remaining credit\n9.view remaining debit\n10.view remaining money for all wallets \n or press 0 to exit\n";
					int filter_choice;
					cin >> filter_choice;
					if (filter_choice == 1)
					{

						EXPENSES.all();

					}

					else if (filter_choice == 2)
					{

						EXPENSES.Filter_By_Date(EXPENSES.getDay());

					}

					else if (filter_choice == 3) {

						EXPENSES.Filter_By_Category(EXPENSES.getCategory());


					}

					else if (filter_choice == 4) {

						EXPENSES.Filter_By_Amount(EXPENSES.get_Minimum_Amount(), EXPENSES.get_Maximum_Amount());
					}
					else if (filter_choice == 5)
					{
						int choice;
						cout << "---enter from the 3 possible multiple filters---" << endl;
						cout << "1.filter by amount and category \n2.filter by amount and date \n3.filter by category and date\n";
						cin >> choice;
						if (choice == 1)
						{

							EXPENSES.Filter_by_Amount_Category(EXPENSES.get_Minimum_Amount(), EXPENSES.get_Maximum_Amount(), EXPENSES.getCategory());

						}
						else if (choice == 2) {

							EXPENSES.Filter_by_Amount_Date(EXPENSES.get_Minimum_Amount(), EXPENSES.get_Maximum_Amount(),
								EXPENSES.getDay());

						}
						else if (choice == 3) {

							EXPENSES.Filter_by_Category_Date(EXPENSES.getCategory(), EXPENSES.getDay());

						}
					}
					else if (filter_choice == 6) {
						EXPENSES.Filter_by_wallet(EXPENSES.getWalletType());
					}
					else if (filter_choice == 7)
					{
						EXPENSES.get_reminig_cash();
					}
					else if (filter_choice == 8)
					{
						EXPENSES.get_reminig_credit();
					}
					else if (filter_choice == 9)
					{
						EXPENSES.get_reminig_debit();
					}
					else if (filter_choice == 10)
					{
						EXPENSES.get_reminig_cash();
						EXPENSES.get_reminig_credit();
						EXPENSES.get_reminig_debit();
					}

					else if (filter_choice == 0)
					{
						break;
					}
				}

			}

		EXPENSES.SaveDataInFile();
		cout << "Do You Want To Enter Another Expenses ? (y/n)" << endl;
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}