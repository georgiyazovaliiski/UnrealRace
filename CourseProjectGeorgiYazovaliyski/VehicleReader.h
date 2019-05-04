#pragma once
#include <string>
#include "LinkedList.h"
#include "Vehicle.h"
#include "Node.h"
class VehicleReader
{
public:
	VehicleReader();
	~VehicleReader();
	void writeInFile(LinkedList<Vehicle>& list);
	std::string* generateArrayParams(int n, std::string paramString, std::string result[]);
	Vehicle* parseVehicle(std::string vehiString);
	void readFromFile(LinkedList<Vehicle> &list);
	
	const std::string fileName = "InitVehicles.txt";
};

