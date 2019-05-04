#include "pch.h"
#include "Car.h"
#include <string>


Car::Car()
{
	this->horse_power = 0;
	this->wheel_brand_name = "no brand name";
}

Car::Car(std::string brandName,
	double gasConsumption,
	std::string tyresbrandName,
	std::string wbn,
	double hp) : WheelFull(tyresbrandName, brandName,gasConsumption)
{
	this->wheel_brand_name = wbn;
	this->horse_power = hp;
}


Car::~Car()
{
}

double Car::get_hp()
{
	return this->horse_power;
}


std::string Car::toString() {
	//Car(BMW,400,Gumi 2,Nqkva marka 12,22250)

	std::string gc = std::to_string(this->gas_consumption);
	std::string hp = std::to_string(this->get_hp());
	std::string line = "Car(";
	line += this->brand_name + ",";
	line += gc;
	line += ",";
	line += this->tyres_brand_name;
	line += ",";
	line += this->wheel_brand_name;
	line += ",";
	line += hp;
	line += ")";

	return line;
};
