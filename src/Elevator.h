#pragma once
#include <bits/stdc++.h>
#include <Windows.h>
#include <unordered_map>
using namespace std;

//ELEVATOR:
class Elevator{
private:
	int curr_Floor, dir, currPassenger, max_Passengers, elev_Id;
	bool isIdle;
public:
	unordered_map<int, int> stops, pickUpPassengers;
	// timeOfDay will cange the lifts position during Initialization:
	Elevator(int timeOfDay, int id, int numElev);
	int Current_Floor();
	int Dir(); 
	void SetDir(int d);
	bool hasSpace();
	bool Idle();
	void Move();
	void addStopsRequestInside(int floor);
	void addStopsRequestOutside(int floor);
};
