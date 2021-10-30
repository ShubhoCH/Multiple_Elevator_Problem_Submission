#include "Elevator.h"
//ELEVATOR:
// timeOfDay will cange the lifts position during Initialization:
Elevator::Elevator(int timeOfDay, int id, int numElev) {
	dir = -1;
	currPassenger = 0;
	max_Passengers = 20;
	isIdle = true;
	elev_Id = id;
	if (timeOfDay == 1)
		curr_Floor = 0;
	else {
		//To find Which section will the elevator initally reside!
		curr_Floor = ((id + 1) / (200 / numElev)) * 200 / numElev;
	}
};
int Elevator::Current_Floor() {
	return curr_Floor;
}
int Elevator::Dir() {
	return dir;
}
void Elevator::SetDir(int d) {
	isIdle = false;
	dir = d;
}
bool Elevator::hasSpace() {
	if (currPassenger < max_Passengers)
		return true;
	return false;
}
bool Elevator::Idle() {
	return isIdle;
}
//Continiously Keep Moving the Elevitor Until is Empty and Ideal:
void Elevator::Move() {
	while (!stops.empty()) {
		Sleep(3000);
		cout << "Inside Elevator:::::" << endl;
		if (dir)
			if (curr_Floor != 200) {
				cout << "Elevator " + to_string(elev_Id) + " Reached at Floor " + to_string(curr_Floor) << endl;
				curr_Floor++;
			}
			else {
				isIdle = true;
				SetDir(-1);
			}
		else
			if (curr_Floor != 0) {
				cout << "Elevator " + to_string(elev_Id) + " Reached at Floor " + to_string(curr_Floor) << endl;
				curr_Floor--;
			}
			else {
				isIdle = true;
				SetDir(-1);
			}
		if (stops.find(curr_Floor) != stops.end()) {
			currPassenger -= stops[curr_Floor];
			stops.erase(curr_Floor);
			cout << "Stops at Floor " + to_string(curr_Floor) << endl;
			//if()
			//
			Sleep(150);
			cout << "Door Opens!" << endl;
			//Take all the Passangers waiting to get Inside!
			if (pickUpPassengers.find(curr_Floor) != pickUpPassengers.end()) {
				cout << "FINALLY:::::::" << endl;
				int totalOnboardingPassangers = pickUpPassengers[curr_Floor];
				for (int i = 1; i <= totalOnboardingPassangers; i++) {
					int temp;
					cout << "Enter Destination Floor for " + to_string(i) + "th Passanger: ";
					cin >> temp;
					addStopsRequestInside(temp);
				}
				cout << to_string(pickUpPassengers[curr_Floor]) + " Passangers Onboarding!" << endl;
				pickUpPassengers.erase(curr_Floor);
				Sleep(1500);
			}
			cout << "Door Closes!" << endl;
			Sleep(100);
			if (stops.empty()) {
				isIdle = true;
				dir = -1;
			}
		}
	}
}
//Add Stops After Passanger Enters the Elevator:
void Elevator::addStopsRequestInside(int floor) {
	if (stops.empty()) {
		stops[floor] = 1;
		currPassenger++;
		Move();
		return;
	}
	if (stops.find(floor) == stops.end()) {
		stops[floor] = 1;
		currPassenger++;
	}
	else {
		stops[floor]++;
		currPassenger++;
	}
}
//Add Stops While passanger is Outside and in the same line of 
//motion as the Elevator:
void Elevator::addStopsRequestOutside(int floor) {
	if (stops.empty()) {
		stops[floor] = 1;
		Move();
		return;
	}
	if (stops.find(floor) == stops.end()) {
		stops[floor] = 1;
	}
	else {
		stops[floor]++;
	}
	//Update no. of people at particular floor:
	if (pickUpPassengers.find(floor) != pickUpPassengers.end())
		pickUpPassengers[floor]++;
	else
		pickUpPassengers[floor] = 1;
}