#pragma once
#include "WheelFull.h"
#include <string>
class Car :
	public WheelFull
{
public:
	Car();
	Car(std::string brandName,
		double gasConsumption, 
		std::string tyresbrandName, 
		std::string wbn,
		double hp);
	~Car();

	// Inherited via WheelFull
	virtual double get_hp() override;
	std::string toString();
private: 
	std::string wheel_brand_name;
	double horse_power;
};

