#include "pch.h"
#include "WheelFull.h"


WheelFull::WheelFull()
{
}

WheelFull::WheelFull(std::string tyresName, std::string brandName, double gasConsumption) : Vehicle(brandName, gasConsumption)
{
	this->tyres_brand_name = tyresName;
}


WheelFull::~WheelFull()
{
}
