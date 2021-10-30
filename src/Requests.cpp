#include "Requests.h"
#include "Controller.h"
//Request:
Requests::Requests() {
	cout << "Created a Request!!!!!!!!!!!" << endl;
}
void Requests::add_Requests(int start, bool dir) {
	if (dir) {
		if (upListOfRequests.find(start) == upListOfRequests.end())
			upListOfRequests[start] = 1;
		else
			upListOfRequests[start]++;
	}
	else {
		if (downListOfRequests.find(start) == downListOfRequests.end())
			downListOfRequests[start] = 1;
		else
			downListOfRequests[start]++;
	}
}
void Requests::Print() {
	//
}
//Cheack all the availble list of Requests and Assign Elevator such that the time
//for waiting in minimum:
void Requests::FindElevators(Controller controller) {
	if (!upListOfRequests.empty()) {
		auto previous = upListOfRequests.begin();
		for (auto it = upListOfRequests.begin(); it != upListOfRequests.end();) {
			bool found = controller.findNearestElevator(it->first, it->second);
			if (found) {
				upListOfRequests.erase(it->first);
				it = upListOfRequests.begin();
			}
			else
				it++;
		}
	}
	if (downListOfRequests.empty()) {
		for (auto it = downListOfRequests.begin(); it != downListOfRequests.end();) {
			bool found = controller.findNearestElevator(it->first, it->second);
			if (found) {
				downListOfRequests.erase(it->first);
				it = downListOfRequests.begin();
			}
			else
				it++;
		}
	}
}