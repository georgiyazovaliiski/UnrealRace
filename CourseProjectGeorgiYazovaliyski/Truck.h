#pragma once
#include "WheelFull.h"
class Truck :
	public WheelFull
{
public:
	Truck();
	Truck(std::string tyresName, std::string brandName, double gasConsumption, double shipment);
	~Truck();

	// Inherited via WheelFull
	virtual double get_hp() override;
	std::string toString();

	double get_shipment();
private:
	double shipment_weight;
};

