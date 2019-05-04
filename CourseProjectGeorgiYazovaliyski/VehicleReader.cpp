#include "pch.h"
#include "VehicleReader.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Train.h"
#include "LinkedList.cpp"

VehicleReader::VehicleReader()
{
}

VehicleReader::~VehicleReader()
{
}

void VehicleReader::writeInFile(LinkedList<Vehicle>& list) {
	std::ofstream myfile(this->fileName);
	
	std::vector<Vehicle*> allVehicles;
	list.generateVector(allVehicles);

	if (myfile.is_open())
	{
		while (allVehicles.size() > 0) {
			myfile << allVehicles.back()->toString() << std::endl;
			allVehicles.pop_back();
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}

std::string* VehicleReader::generateArrayParams(int n, std::string paramString, std::string result[]) {
	int arrayJ = 0;
	std::string temp = "";
	for (int i = paramString.find('(') + 1; i < paramString.size() - 1; i++)
	{
		if (paramString[i] == ',') {
			result[arrayJ] = temp;
			temp = "";
			i++;
			arrayJ++;
		}
		temp += paramString[i];
	}
	result[arrayJ] = temp;

	return result;
}

Vehicle* VehicleReader::parseVehicle(std::string vehiString) {
		std::string vehiType = vehiString.substr(0, vehiString.find('('));

		if (vehiType == "Car") {
			std::string arrayParams[5];
			generateArrayParams(5, vehiString, arrayParams);

			Car* car = new Car(arrayParams[0],
				stod(arrayParams[1]),
				arrayParams[2],
				arrayParams[3],
				stod(arrayParams[4]));

			return car;
		}
		else if (vehiType == "Truck") {
			std::string arrayParams[4];
			generateArrayParams(4, vehiString, arrayParams);

			Truck* truck = new Truck(
				arrayParams[0],
				arrayParams[1],
				stod(arrayParams[2]),
				stod(arrayParams[3]));

			return truck;
		}
		else if (vehiType == "Train") {
			std::string arrayParams[5];
			generateArrayParams(5, vehiString, arrayParams);

			Train* train = new Train(arrayParams[0],
				stod(arrayParams[1]),
				arrayParams[2],
				stoi(arrayParams[3]),
				arrayParams[4]);

			return train;
		}
		return nullptr;
	
}

void VehicleReader::readFromFile(LinkedList<Vehicle> &list) {
	std::string line;
	std::ifstream myfile(this->fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			Vehicle* v = parseVehicle(line);
			list.push(new Node<Vehicle>(v));
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
}
