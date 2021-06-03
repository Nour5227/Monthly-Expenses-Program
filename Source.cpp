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

			cout << " \n How do you want to view your expenses?" << endl
				<< "1.view all \n2.view by date \n3.view by category \n4.view by amount \n5.view by multiple\n or press 0 to exit\n";
			int filter_choice;
			cin >> filter_choice;
			if (filter_choice == 1)
			{

				EXPENSES.all();

			}

			else if (filter_choice == 2)
			{
				/*int Day;
				cout << "Enter the Day " << endl;
				cin >> Day;*/
				EXPENSES.Filter_By_Date(EXPENSES.getDay());

			}

			else if (filter_choice == 3) {
				/*string category;
				cout << "Enter The Name Of The Category" << endl;
				cin >> category;*/
				EXPENSES.Filter_By_Category(EXPENSES.getCategory());


			}

			else if (filter_choice == 4) {
				
				EXPENSES.Filter_By_Amount(EXPENSES.get_Minimum_Amount() , EXPENSES.get_Maximum_Amount());
			}
			else if (filter_choice == 5)
			{
				int choice;
				cout << "---enter from the 3 possible multiple filters---" << endl;
				cout << "1.filter by amount and category \n2.filter by amount and date \n3.filter by category and date\n";
				cin >> choice;
				if (choice == 1)
				{
				 /* int l1, l2;
				  string s;
		          cout << "enter minimum amount" << endl;
			      cin >> l1;
		          cout << "enter maximum amount" << endl;
		 	      cin >> l2;
				  cout << "enter the name of the category" << endl;
				  cin >> s;*/
				  EXPENSES.Filter_by_Amount_Category(EXPENSES.get_Minimum_Amount(), EXPENSES.get_Maximum_Amount(), EXPENSES.getCategory());
				      
				}
				else if (choice == 2){
					/*int n1, n2;
					int d;
					cout << "enter minimum amount" << endl;
					cin >> n1;
					cout << "enter maximum amount" << endl;
					cin >> n2;
					cout << "enter the day" << endl;
					cin >> d;*/
					EXPENSES.Filter_by_Amount_Date(EXPENSES.get_Minimum_Amount(), EXPENSES.get_Maximum_Amount(), 
						EXPENSES.getDay());
					
				}
				else if (choice == 3){
					/*int da;
					string cat;
					cout << "enter the name of the category" << endl;
					cin >> cat;
					cout << "enter the day" << endl;
					cin >> da;*/
					EXPENSES.Filter_by_Category_Date(EXPENSES.getCategory(), EXPENSES.getDay());
					
				}
			}
			
			else if(filter_choice == 0)
			{
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