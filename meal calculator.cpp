/*
file:	meal calculator
by:		Justin Smith
org:	COP 2001, Spring 2020
for:	Develop a simple meal calculator requiring user input for meal cost, and tip rate with full receipt
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;


int main() {						// Start main


	int const DISPLAY_WIDTH = 25;							// Constants
	float const TAX_RATE = 6.50;							// tax = 6.5%
	string const SPACES = "                         ";		// 25 spaces
	string const DASHES = "-------------------------";		// 25 dashes


	string companyName = "Good Burger";

	float tipRate,
		mealCost;

	bool goodValues = false;

	do {
		cout << "Enter meal cost: $";
		cin >> mealCost;

		cout << "Enter tip rate (i.e. 20.00%): ";
		cin >> tipRate;

		if ((tipRate <= 100.00) && (tipRate >= 0.00)) {
			goodValues = true;
		}
		
		cout << "\n\n";

	} while (!goodValues);


	if (tipRate < 1.00) {			// Checks for a tip rate in decimal form (ie .10 = 10%)
		tipRate *= 100;				// Assuming customer doesn't want to tip < 1%
	}

	string labelString;
	int labelWidth;
	


	cout << SPACES.substr(0, (DISPLAY_WIDTH - companyName.length()) / 2)
		<< companyName << endl;
	

	cout << DASHES << endl;
	

	labelString = "Meal:";
	labelWidth = labelString.length();
	cout << "Meal:" << fixed << setprecision (2)
		<< SPACES.substr(0, DISPLAY_WIDTH - labelWidth - (to_string(mealCost).length()-3))
		<< '$' << mealCost << endl;


	labelString = "Tax:";
	labelWidth = labelString.length();
	cout << "Tax:" << SPACES.substr(0, DISPLAY_WIDTH - labelWidth - (to_string(TAX_RATE).length()-4))
		<< TAX_RATE << '%' << endl;


	cout << DASHES << endl;


	float subtotal = mealCost + ((mealCost * TAX_RATE) / 100);
	float tip = (subtotal * tipRate) / 100;
	

	labelString = "Subtotal:";
	labelWidth = labelString.length();
	cout << "Subtotal:" << SPACES.substr(0, DISPLAY_WIDTH - labelWidth - (to_string(subtotal).length()-3))
		<< '$' << subtotal << endl;


	labelString = "Tip:";
	labelWidth = labelString.length();
	cout << "Tip:" << SPACES.substr(0, DISPLAY_WIDTH - labelWidth - (to_string(tip).length() - 3))
		<< '$' << tip << endl;


	cout << DASHES << endl;


	float total = subtotal + tip;

	labelString = "Total:";
	labelWidth = labelString.length();
	cout << "Total:" << SPACES.substr(0, DISPLAY_WIDTH - labelWidth - to_string(total).length() + 3)
		<< '$' << total << endl;



	return 0;
}									// End main