#include "pch.h"
#include "Vehicle.h"
#include <chrono>
#include <ctime> 
#include <iostream> 


Vehicle::Vehicle()
{
}

Vehicle::Vehicle(std::string brandName, double gasConsumption)
{
	//this->idcode = generateId();
	this->brand_name = brandName;
	this->gas_consumption = gasConsumption;
}


Vehicle::~Vehicle()
{
}

std::string Vehicle::get_brand_name()
{
	return this->brand_name;
}

std::string Vehicle::generateId()
{
	auto start = std::chrono::system_clock::now();
	// Some computation here
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << end_time
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	return std::string();
}
