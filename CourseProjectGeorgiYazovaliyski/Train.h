#pragma once
#include "WheelLess.h"
class Train :
	public WheelLess
{
public:
	Train(std::string brandName, double gasConsumption, std::string movement, int amount_passengers_possible, std::string horse_power_code);
	~Train();

	// Inherited via WheelLess
	virtual double get_hp() override;
	std::string toString();
private:
	int amount_passengers_possible;
	std::string horse_power_code;
};

