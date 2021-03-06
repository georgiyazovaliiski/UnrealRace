// CourseProjectGeorgiYazovaliyski.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "LinkedList.h"
#include "Vehicle.h"
#include "Node.h"
#include "VehicleReader.h"
#include "LinkedList.cpp"
#include "Node.cpp"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

void showMenu() {
	cout << "Menu:" << endl;
	cout << "1. Show vehicles" << endl;
	cout << "2. Add vehicle" << endl;
	cout << "3. Remove vehicle" << endl;
	cout << "4. Save vehicles" << endl;
	cout << "5. Show menu again" << endl;
	cout << "Q -> Quit." << endl;
}

int main()
{
	showMenu();
	LinkedList<Vehicle> list;
	VehicleReader reader;

	reader.readFromFile(list);

	char c;
	cin >> c;
	while (c != 'Q') {
		system("cls");
		switch (c) {
		case '1':
			list.print();
			break;
		case '2': {
			cout << "Input vehicle data: "<<endl;
			string command_line;
			cin.ignore();
			getline(cin,command_line);
			
			Vehicle* v = reader.parseVehicle(command_line);
			if (v) {
				list.push(new Node<Vehicle>(v));
				cout << "Vehicle added successfully!" << endl;
			}
			break;
		}
		case '3': {
			cout << "Input removing vehicle place: " << endl;
			string command_line;
			cin.ignore();
			getline(cin, command_line);

			try {
				int id = stoi(command_line);
				list.remove(id);
			}
			catch (exception e) {
				continue;
			}
			break;
		}
		case '4':
			reader.writeInFile(list);
			break;
		case '5':
			showMenu();
			break;
		default:
			cout << "Wrong command try again(Option 5 to Show Menu!): " << endl;
			break;
		}
		cout << "Insert command(5 for menu): " << endl;
		cin>>c;
	}

	cout << "Bye!" << endl;
	return 0;
}
