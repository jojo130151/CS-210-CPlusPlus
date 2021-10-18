#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void dataInput(double& initInvestment, double& monthlyDeposit, double& annualInterest, int& numYears) {
	/* Output prompts to user to get values for initial investment, monthly deposit, annual interest percentage,
	 * and the number of years they are interested in seeing. Function includes exception to catch invalid values from user. */
	try {
		// Output header of data input table to user
		cout << "******************************" << endl;
		cout << "**********" << "Data Input" << "**********" << endl;
		// Prompt user and check input for wrong type
		cout << "Initial Investment Amount: $";
		while (!(cin >> initInvestment)) {
			cin.clear();
			cin.ignore();
			throw 0;
		}
		if (initInvestment < 0) {
			throw 0;
		}
		cout << "Monthly Deposit: $";
		while (!(cin >> monthlyDeposit)) {
			cin.clear();
			cin.ignore();
			throw 0;
		}
		if (monthlyDeposit < 0) {
			throw 0;
		}
		cout << "Annual Interest: %";
		while (!(cin >> annualInterest)) {
			cin.clear();
			cin.ignore();
			throw 0;
		}
		if (annualInterest < 0) {
			throw 0;
		}
		cout << "Number of years: ";
		while (!(cin >> numYears)) {
			cin.clear();
			cin.ignore();
			throw 0;
		}
		if (numYears < 0) {
			throw 0;
		}
		system("pause"); // Prompt the user to press a key to continue when they are ready
	}
	catch (int e) { // Display message to user prompting correct input, clear screen, and restart input proccess for user
		system("CLS");
		cout << "Please enter only positive numerical values." << endl << endl;
		dataInput(initInvestment, monthlyDeposit, annualInterest, numYears);
	}
}

void withoutDeposits(int t_years, double t_investment, double t_interest) {
	double interestAmount;  // Variable that stores interest amount based on investment

	// Output header of data table to user
	cout << "      Balance and Interest Without Additional Monthly Deposits      " << endl;
	cout << "====================================================================" << endl;
	cout << "   Year        Year End Balance        Year End Earned Interest     " << endl;
	cout << "--------------------------------------------------------------------" << endl;

	// For loop to iterate through years given by user
	for (int i = 1; i <= t_years; ++i) {
		interestAmount = t_interest * t_investment;  // Calculate interest amount by multiplying investment by interest percentage
		t_investment = t_investment + interestAmount;// Add interest amount to investment total
		// Output data to user based on their given values
		cout << fixed << setprecision(2) << right << setw(6) << i;
		cout << right << setw(20) << t_investment;
		cout << right << setw(27) << interestAmount << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
	cout << endl << endl;
}

void withDeposits(int t_years, double t_monthlyDeposit, double t_investment, double t_interest) {
	double interestAmount = 0; // variable to hold interst amount
	double totalYearInterest = 0; // holds yearly interest earned

	t_interest = t_interest / 12;

	// Out put header for data to user
	cout << "        Balance and Interest With Additional Monthly Deposits       " << endl;
	cout << "====================================================================" << endl;
	cout << "   Year        Year End Balance        Year End Earned Interest     " << endl;
	cout << "--------------------------------------------------------------------" << endl;

	// For  loop to iterate through given vale for number of years
	for (int i = 1; i <= t_years; ++i) {
		totalYearInterest = 0;                             // Resets value of totalYearInterest each year iteration
		for (int month = 1; month <= 12; ++month) {        // A for loop to calculate monthly deposits and interest
			t_investment += t_monthlyDeposit;              // Add monthly deposit
			interestAmount = t_interest * t_investment;    // Determine interest amount by multiplying current investment amount by monthly interest amount
			t_investment = t_investment + interestAmount;  // Update investment amount by adding our calculated interest
			totalYearInterest += interestAmount;           // Keep up with the yearly interest by adding monthly interest
		}
		// Output values to user
		cout << fixed << setprecision(2) << right << setw(6) << i;
		cout << right << setw(20) << t_investment;
		cout << right << setw(27) << totalYearInterest << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
	cout << endl << endl;
}

int main() {
	double initInvestment = 0.00; // Initial invest amount inputted by user
	double monthlyDeposit = 0.00; // Monthly investment amount inputted by user
	double annualInterest = 0.00; // Rate of annual interest inputted by user
	int numYears = 0; // Number of years user is interested in
	char userChar = 'a'; // User input character to use While loop

	while (userChar != 'q') {
		system("CLS");

		dataInput(initInvestment, monthlyDeposit, annualInterest, numYears);

		annualInterest = annualInterest / 100;  // Change interest from percentage to decimal

		system("CLS"); // Clear screen from data input table

		withoutDeposits(numYears, initInvestment, annualInterest);
		withDeposits(numYears, monthlyDeposit, initInvestment, annualInterest);

		// Output options of continuing for user
		cout << "To quit program press the 'q' key." << endl;
		cout << "To continue trying out diffent values, press any other key and hit enter" << endl;
		cin >> userChar;
	}
}

