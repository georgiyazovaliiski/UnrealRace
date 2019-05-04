#include "pch.h"
#include "Train.h"


Train::Train(std::string brandName, double gasConsumption, std::string movement, int amount_passengers_possible, std::string horse_power_code) : WheelLess(brandName,gasConsumption,movement)
{
	this->amount_passengers_possible = amount_passengers_possible;
	this->horse_power_code = horse_power_code;
}


Train::~Train()
{
}

double Train::get_hp()
{
	double result = 0;
	// THIS FUNCTION WILL PROCESS THE STRING CODE AND ESTIMATE THE HORSE POWER
	int i = 0;
	for (i; i < this->horse_power_code.length()-1; i++)
	{
		switch (horse_power_code[i]) {
		case 'A':
			result += 6;
			break;
		case 'B':
			result += 6;
			break;
		case 'C':
			result += 6;
			break;
		case 'D':
			result += 6;
			break;
		case 'E':
			result += 6;
			break;
		}
	}
	int multiplier = horse_power_code[i] - '0';
	return result*multiplier;
}
std::string Train::toString() {
	std::string gc = std::to_string(this->gas_consumption);
	std::string passengers = std::to_string(this->amount_passengers_possible);
	std::string line = "Train(";
	line += this->brand_name;
	line += ",";
	line += gc;
	line += ",";
	line += this->movement;
	line += ",";
	line += passengers;
	line += ",";
	line += this->horse_power_code;
	line += ")";

	return line;
};
