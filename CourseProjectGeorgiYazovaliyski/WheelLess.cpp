#include "pch.h"
#include "WheelLess.h"


WheelLess::WheelLess(std::string brandName, double gasConsumption, std::string movement)
{
	this->brand_name = brandName;
	this->gas_consumption = gasConsumption;
	this->movement = movement;
}


WheelLess::~WheelLess()
{
}
