#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
	long a = 0, b = 0, c = 0;
	string flag = "flag{contained_in_margins}";
	cout << endl << "----WELCOME TO THE FERMAT CHECKER----" << endl;
	cout << "-------------note: n = 3-------------" << endl << endl;
	//c++ official guide!
	while ((cout << "Please enter the number A: ") && (!(cin >> a) || a < 1)) {
		cout << "That's not a number greater than 0. ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while ((cout << "Please enter the number B: ") && (!(cin >> b) || b < 1)) {
		cout << "That's not a number greater than 0. ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while ((cout << "Please enter the number C: ") && (!(cin >> c) || c < 1)) {
		cout << "That's not a number greater than 0. ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (a*a*a + b*b*b == c*c*c) {
		cout << "Congratulations! Here's your flag: " << flag << endl;
	} else {
		cout << "Sorry, try again." << endl;
	}
}
