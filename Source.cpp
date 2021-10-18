/* Jordan Davis
 * CS-210
 * Project One
 * 09/19/2021
*/
# define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<time.h>
#include<string>
#include<cstdlib>
#include<iomanip>

using namespace std;

void PrintMenu() {
	/* Prints out the menu options to the user */
	std::cout << "*************************" << '\n';
	std::cout << "* 1 - Add One Hour      *" << '\n';
	std::cout << "* 2 - Add One Minute    *" << '\n';
	std::cout << "* 3 - Add One Second    *" << '\n';
	std::cout << "* 4 - Exit Program      *" << '\n';
	std::cout << "*************************" << '\n';
}

void PrintClocks(int hours, int minutes, int seconds, string str) {
	/* Assigns str with either "PM" or "AM" and assigns the right hours to display on the correct clock. Outputs clocks
	 * for 12 hour time format and 24 hour time format."*/
	int hours12;                // holds the 12-hour format hours value
	if (hours > 12) {           // Assigns the right hours with the right str
		hours12 = hours - 12;
		str = "PM";
	}
	else if (hours == 00) {
		hours12 = 12;
		str = "AM";
	}
	else if (hours == 12) {
		str = "PM";
		hours12 = 12;
	}
	else {
		hours12 = hours;
		str = "AM";
	}

	// Outputs the two clocks to user screen
	std::cout << "*************************" << "  " << "*************************" << '\n';
	std::cout << '*' << "     " << "12-Hour Clock" << "     " << '*';
	std::cout << "  " << '*' << "     " << "24-Hour Clock" << "     " << '*' << '\n';
	std::cout << '*' << "      " << (hours12 < 10 ? "0" : "") << hours12 << ":" << (minutes < 10 ? "0" : "");
    std::cout << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str << "      " << '*';
	std::cout << "  " << '*' << "       " << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "");
	std::cout << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << "        " << '*' << '\n';
	std::cout << "*************************" << "  " << "*************************" << '\n';
}

void AddHour(int& hours) {
	/* Adds an hour based on user input and if minutes exceed 59. Resets hours if it exceeds 23 to 00.*/
	if (hours < 23) {
		hours += 1;
	}
	else if (hours == 23) {
		hours = 00;
	}
}

void AddMinute(int& minutes, int& hours) {
	/* Adds an additional minute to the clock based on user input and if seconds exceed 59.
	 * Resets minutes to 00 if minutes exceeds 59 and adds an hour. */
	if (minutes < 59) {
		minutes += 1;
	}
	else if (minutes == 59) {
		minutes = 00;
		AddHour(hours);
	}
}

void AddSecond(int& seconds, int& minutes, int& hours) {
	/* Adds an additinal second to the clock based on user input. Resets seconds to 00 if seconds 
	 * exceed 59 and adds a minute.*/
	if (seconds < 59) {
		seconds += 1;
	}
	else if (seconds == 59) {
		seconds = 00;
		AddMinute(minutes, hours);
	}
}


int main() {
	int seconds;
	int minutes;
	int hours;            // Stores the variables taken from localtime
	string str;           // Holds either "PM" or "AM".
	int menuInput;
	bool loopBool = true; // Boolean for while loop

	time_t totalSeconds = time(0);            // Gets current time
	struct tm* ct = localtime(&totalSeconds);

	seconds = ct->tm_sec;
	minutes = ct->tm_min;
	hours = ct->tm_hour;   // Breaks down current time into seconds, minutes, and hours
	
	while (loopBool) {
		system("CLS");                              // Clears screen
		PrintClocks(hours, minutes, seconds, str);  // Output clocks
		PrintMenu();                                // Output menu
	    
	    cin >> menuInput;                           // Get user input for menu
		switch (menuInput) {
			case 1:
				AddHour(hours);
				break;
			case 2:
				AddMinute(minutes, hours);
				break;
			case 3:
				AddSecond(seconds, minutes, hours);
				break;
			case 4:
				cout << "Goodbye.";
				loopBool = false;                    // Change boolean to exit program
				break;
			default:
				break;
		}
	}
}