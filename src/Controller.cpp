#include "Controller.h"
#include "Elevator.h"
using namespace std;
//CONTROLLER:
Controller::Controller(int numElev, int timeOfDay) {
	noOfElevators = numElev;
	cout << numElev << endl;
	for (int i = 0; i < numElev; i++) {
		//Create required number of Elevator Objects:
		Elevator elevator(timeOfDay, i, numElev);
		elevators.push_back(elevator);
	}
};
//Find the nearest Available Elevator that either in the correct line 
//of motion Or is Ideal or With for any Elevator to change Direction:
int Controller::findNearestElevator(int floor, int dir) {
	int index = -1;
	int minFloorDiff = INT_MAX;
	cout << elevators.size() << endl;;
	for (int i = 0; i < elevators.size();i++) {
		if (elevators[i].hasSpace()) {
			int floorDiff = INT_MAX;
			if (dir == elevators[i].Dir() || elevators[i].Idle()) {
				if (elevators[i].Idle()) {
					index = i;
					if (elevators[i].Current_Floor() < floor)
						elevators[i].SetDir(1);
					else
						elevators[i].SetDir(0);
					minFloorDiff = abs(floor - elevators[i].Current_Floor());
				}
				else if (elevators[i].Dir() == 1 && elevators[i].Current_Floor() < floor)
					floorDiff = floor - elevators[i].Current_Floor();
				else if (elevators[i].Dir() == 0 && elevators[i].Current_Floor() > floor)
					floorDiff = elevators[i].Current_Floor() - floor;
				else
					continue; //"You have to wait until an elevator is Empty or Changes Direction!";
				if (floorDiff < minFloorDiff) {
					minFloorDiff = floorDiff;
					index = i;
				}
				/*else if (floorDiff == minFloorDiff && floorDiff != INT_MAX)
					index = i;*/
			}
		}
	}
	cout << "INDEX: " + to_string(index) << endl;
	if (index == -1)
		return false;
	//Add in stops map to stop;
	elevators[index].addStopsRequestOutside(floor);
	return true;
};
void Controller::PrintElevPos() {
	for (int i = 0; i < noOfElevators; i++) {
		cout << elevators[i].hasSpace() << endl;
	}
};