#pragma once
#include <string>
#include "Vehicle.h"
class WheelLess : public Vehicle
{
public:
	WheelLess(std::string brandName, double gasConsumption, std::string movement);
	~WheelLess();
	virtual double get_hp() = 0;
	virtual std::string toString() = 0;
protected: 
	std::string movement;	// Water, Air, Rails
};

