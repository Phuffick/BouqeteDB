#include "database.h"

int main() { 
	Database db; 
	std::string command;
	std::cout << "Write /help to lern more.\n"; 
	while (std::getline(std::cin, command)) {
		try {
			std::string firstCommand = split(command, '/');

			if (firstCommand == "Add") {
				std::string secondCommand = split(command, '/');

				if (secondCommand == "flower") {

					std::string flowerName = split(command, '/');
					std::string freshness = split(command, '/').c_str();
					std::string color = split(command, '/').c_str();
					std::string length = split(command, '\n');

					db.AddFlower(flowerName, 
						freshnessCast(freshness),
						colorCast(color),
						lengthCast(length));
				}
				else if(secondCommand == "sweet") {

					std::string sweetName = split(command, '/');
					int packageType = atoi(split(command, '/').c_str());
					std::string number_of_sweeets = split(command, '\n');

					db.AddSweet(sweetName, 
						static_cast<Package>(packageType), 
						numberOfSweeetsCast(number_of_sweeets));
				}
				else {
					throw std::runtime_error("Invalid data.");
				}
			}
			else if (firstCommand == "DeleteItem") {

				std::string command_second = split(command, '/');

				if (command_second == "flower") {

					std::string flower_name = split(command, '/');
					std::string freshness = split(command, '/').c_str();
					std::string color = split(command, '/').c_str();
					std::string length = split(command, '\n');

					db.DeleteFlower(flower_name, 
						freshnessCast(freshness),
						colorCast(color),
						lengthCast(length));
				}
				else if (command_second == "sweet") {

					std::string sweet_name = split(command, '/');
					int packageType = atoi(split(command, '/').c_str());
					std::string numberOfSweeets = split(command, '\n');

					db.DeleteSweet(sweet_name, 
						static_cast<Package>(packageType), 
						numberOfSweeetsCast(numberOfSweeets));
				}
				else {
					throw std::runtime_error("Invalid data.");
				}
			}
			else if (firstCommand == "Sort") {
				db.Sort();
			}
			else if (firstCommand == "Delete") {
				db.Delete();
				std::cout << "Deleted successfully\n";
			}
			else if (firstCommand == "PrintRange") {

				int inf = atoi((split(command, '/')).c_str());
				int sup = atoi((split(command, '\n')).c_str());

				db.PrintRange(inf, sup);
			}
			else if (firstCommand == "Print") {
				db.Print();
			}
			else if (command == "help") {
				std::cout << '\n' << "ADD FLOWER TEMPLATE: Add/flower/*flower_name*/*freshness(from_1_to_11)*/*color*/*length*\n"
					<< "ADD SWEET TEMPLATE: Add/sweet/*sweet_name*/*type_(from_1_to_10)*/*number_of_sweets*\n"
					<< "DELETE FLOWER TEMPLATE: DeleteItem/flower/*flower_name*/*flower_name*/*freshness(from_1_to_11)*/*color*/*length*\n"
					<< "DELETE SWEET TEMPLATE: DeleteItem/sweet/*sweet_name*/*flower_name*/*freshness(from_1_to_11)*/*color*/*length*\n"
					<< "SORT TEMPLATE: Sort\n" 
					<< "DELETE TEMPLATE: Delete\n" 
					<< "PRINT RANGE TEMPLATE: PrintRange/*from_length(cm)*/*to_length(cm)*\n"
					<< "PRINT ALL TEMPLATE: Print\n"
					<< "CLOSE PROGRAM TEMPLATE: Exit\n\n"
					<< "FLOWERS: \n"
					<< "'rose'   'forget_me_not'   'orchid'    'snowdrop'    'tulip'   'violet'\n"
					<< "SWEETS: \n"
					<< "'chocolate'   'candy'\n" 
					<< "PACKAGE TYPES: \n"
					<< "'type_1'   'type_2'   'type_3'    'type_4'    'type_5'   'type_6'   'type_7'   'type_8'    'type_9'    'type_10'\n"
					<< "COLORS: \n"
					<< " 'red'   'blue'   'yellow'   'orange'   'pink'   'green'   'white'   'lilac'\n\n"
					<< "FRESHNESS: \n"
					<< " 'one_day'   'two_days'   'three_days'   'four_days'   'five_days'" << 
					"   'six_days'   'seven_days'   'eight_days'   'nine_days'   'ten_days'   'more_than_ten_days' \n\n";
			}
			else if (firstCommand == "" || firstCommand == " " || firstCommand == "\n") {}
			else if (firstCommand == "Exit") {
				std::cout << "Program finished successfully without any error.\n";
				return 0;
			}
			else {
				std::cout << "Unknown command: " << command << '\n';
			}
			firstCommand.clear();
		}
		catch (std::exception& exeption) {
			std::cout << exeption.what() << '\n';
			return 0;
		};
		command.clear();
	}

	return 0;
}