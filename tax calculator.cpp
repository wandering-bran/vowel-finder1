#include <iostream>


using namespace std;
void getData(double& gross, double& pension, char& status, double& kids);
void taxAmount(double& gross, double& pension, double& kids, char& status, double& tax);
int main()
{
	double gross, pension, tax, kids;
	char status, control;
	bool run=true;

	while (run == true)
	{
		cout << "greetings tax-paying user! today is the day we calculate "
			<< "your federal tax.\nvery exiting!" << endl;

		getData(gross, pension, status, kids);
		taxAmount(gross, pension, kids, status, tax);
	
		cout << "the tax you would owe is: $" << tax << endl;
		cout << "would you like to run the program again?"
			<< "\ny for yes, no for no: ";
			cin >> control;
			if (control == 'y' || control == 'Y')
				gross = 0, pension = 0, tax = 0, kids = 0;
			else if (control == 'n' || control == 'N')
				run = false;
			else
			{
				cin.clear();
				cin.ignore();
				cout << "that is not correct. please enter y or n to continue: ";
				cin >> control;
			}
	}
	
	return 0;
}
void getData(double& gross, double& pension, char& status, double& kids)
{
	cout << "time to answer some very personal questions.\nare you married?"
		<< " enter y for yes, n for no: ";
	cin >> status;
	cout << endl;
	cout << "thank you! do you have any children under the age of 14?"
		<< "\nplease enter the number of children (input 0 if none): ";
	cin >> kids;
	cout << endl;
	if (status == 'y' || status == 'Y')
	{
		cout << "now enter you and your spouses gross combined income: $";
		cin >> gross;
		cout << endl;
	}
	else
	{
		cout << "now enter your gross income: $";
		cin >> gross;
		cout << endl;
	}

	cout << "almost done! last question: "
		<< "\nwhat percentage of your gross income did you contribute"
		<< "\ntowards a pension fund? "
		<< "(maximum is 6%; if none enter 0;\ndo not enter percentage sign, only numeric value): ";
	cin >> pension;
	cout << endl;
	if (pension > 6 || pension < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "that is incorrect please try again."
			<< "\nwhat percentage of your gross income did you contribute"
			<< "\ntowards a pension fund? "
			<< "(maximum is 6%; if none enter 0;\ndo not enter percentage sign, only numeric value) ";
		cin >> pension;
	}
}
void taxAmount(double& gross, double& pension, double& kids, char& status, double& tax)
{
	double taxInc;
	double actPen = (pension * .01) * gross;


	if (status == 'y' || status == 'Y')
	{
		taxInc = gross - (10000 + (kids * 1500) + actPen);
	}
	else
	{
		taxInc = gross - (5500 + (kids * 1500) + actPen);
	}

	if (taxInc >= 0 && taxInc <= 15000)
		tax = taxInc * .15;
	else if (taxInc >= 15001 && taxInc <= 40000)
		tax = (0.25*(taxInc - 15000)) + 2250;
	else if (taxInc > 40000)
		tax = (0.35*(taxInc - 40000)) + 8460;
	else
		tax = 0;
}