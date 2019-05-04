#pragma once
#include "Vehicle.h"
#include <string>
class WheelFull : public Vehicle
{
public:
	WheelFull();
	WheelFull(std::string tyresName, std::string brandName, double gasConsumption);
	~WheelFull();
	virtual double get_hp() = 0;
	virtual std::string toString() = 0;
protected:
	std::string tyres_brand_name;
};

