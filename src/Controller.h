#pragma once
#include <vector>
#include <iostream>
#include "Elevator.h"
using namespace std;
//CONTROLLER:
class Controller {
private:
public:
	int noOfElevators;
	vector<Elevator> elevators;
	Controller(int numElev, int timeOfDay);
	int findNearestElevator(int floor, int dir);
	void PrintElevPos();
};