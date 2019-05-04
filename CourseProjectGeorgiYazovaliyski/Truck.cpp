#include "pch.h"
#include "Truck.h"


Truck::Truck()
{
}

Truck::Truck(std::string brandName, std::string tyresName, double gasConsumption, double shipment) : WheelFull(tyresName,brandName, gasConsumption)
{
	this->shipment_weight = shipment;
}


Truck::~Truck()
{
}

double Truck::get_hp()
{
	return this->shipment_weight * 2.1;
}

double Truck::get_shipment()
{
	return this->shipment_weight;
}


std::string Truck::toString() {
	//Truck(Toyota,Deaznam,12.34,12.34)
	
	std::string line = "Truck(";
	line += this->brand_name;
	line += ",";
	line += this->tyres_brand_name;
	line += ",";
	line += std::to_string(this->gas_consumption);
	line += ",";
	line += std::to_string(this->shipment_weight);
	line += ")";

	return line;
};
