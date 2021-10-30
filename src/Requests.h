#pragma once
//Request:
#include "Controller.h"
#include <unordered_map>
using namespace std;
class Requests {
public:
	//Will store Floor and noOfPeople at that floor; 
	unordered_map<int, int> upListOfRequests;
	unordered_map<int, int> downListOfRequests;
	Requests();
	void add_Requests(int start, bool dir);
	void Print();
	void FindElevators(Controller controller);
};
