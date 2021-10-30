#include "Controller.h"
#include "Requests.h"
#include "Elevator.h"
int main() {
	int noOfLifts, noOfPeople, timeOfDay;
	cout << "Enter number of Lifts: ";
	cin >> noOfLifts;
	// Create a Controller for the elevators;
	Requests requests;
	cout << "Enter number of People: ";
	cin >> noOfPeople;
	cout << "Enter 1 if Time is between 8 - 9 other wise press anything other than 1 : ";
	cin >> timeOfDay;
	Controller controller(noOfLifts, timeOfDay);
	for (int i = 0; i < noOfPeople; i++) {
		int start, dir;
		cout << "Enter Start Floor for Person" + to_string(i + 1) + ": ";
		cin >> start;
		cout << "Enter 1 for upward and 0 for Down direction for Person " + to_string(i + 1) + ": ";
		cin >> dir;
		requests.add_Requests(start, dir);
	}
	while (true) {
		requests.FindElevators(controller);
		Sleep(1000);
	}
	//requests.Print();
	//Start finding Elevetors:
	//Update no of Lifts:
}