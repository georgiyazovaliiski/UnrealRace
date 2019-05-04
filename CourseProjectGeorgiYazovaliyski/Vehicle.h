#pragma once
#include <string>
class Vehicle
{
public:
	Vehicle();
	Vehicle(std::string brandName, double gasConsumption);
	~Vehicle();
	virtual double get_hp() = 0;
	std::string get_brand_name();

	virtual std::string toString() = 0;

protected:
	std::string idcode;
	std::string brand_name;
	double gas_consumption;
private:
	std::string generateId();
};

