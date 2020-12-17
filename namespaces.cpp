#include "namespaces.h"

std::map <std::string, Color> color_map = { { "red", Color::Red }, {"blue", Color::Blue},
											{ "yellow", Color::Yellow }, {"orange", Color::Orange},
											{ "pink", Color::Pink }, {"green", Color::Green},
											{ "white", Color::White }, {"lilac", Color::Lilac} };

std::map <std::string, Package> package_map = { { "type_1", Package::Type_1 }, {"type_2", Package::Type_2},
												{ "type_3", Package::Type_3 }, {"type_4", Package::Type_4},
												{ "type_5", Package::Type_5 }, {"type_6", Package::Type_6},
												{ "type_7", Package::Type_7 }, {"type_8", Package::Type_8},
												{ "type_9", Package::Type_9 }, {"type_10",Package::Type_10} };

std::map <std::string, Freshness> freshness_map = { { "one_day", Freshness::one_day },         { "two_days", Freshness::two_days },
													{ "three_days", Freshness::three_days },   { "four_days", Freshness::four_days },
													{ "five_days", Freshness::five_days },     { "six_days", Freshness::six_days },
													{ "seven_days", Freshness::seven_days },   { "eight_days", Freshness::eight_days },
													{ "nine_days", Freshness::nine_days },     { "ten_days", Freshness::ten_days },
													{ "more_than_ten_days", Freshness::more_than_ten } };

std::string split(std::string& s, const char& sepator) {
    std::string res_string = "";
    std::string s_copy = s;
    bool split_flag = true;
	for (char& ch : s_copy) {
		if (!split_flag) {
			s += ch;
		}
		if (split_flag) {
			if ((ch != sepator)) {
				res_string += ch;
			}
			else {
				split_flag = false;
				s.clear();
			}
		}
	}

	return res_string;
}

std::ostream& operator << (std::ostream& out, const Color& color) {
	switch (color) {
	case Color::Red: return (out << "red");
	case Color::Blue: return (out << "blue");
	case Color::Yellow: return (out << "yellow");
	case Color::Orange: return (out << "orange");
	case Color::Pink: return (out << "pink");
	case Color::Green: return (out << "green");
	case Color::White: return (out << "white");
	case Color::Lilac: return (out << "lilac");
	}
	return (out);
}

std::ostream& operator << (std::ostream& out, const Freshness& freshness) {
	if (freshness == Freshness::more_than_ten) {
		std::cout << "more than ten";
		return out;
	}
	std::cout << (int)freshness;
	return out;
}

std::ostream& operator << (std::ostream& out, const Package& package) {
	switch (package) {
	case Package::Type_1: return (out << "type_1");
	case Package::Type_2: return (out << "type_2");
	case Package::Type_3: return (out << "type_3");
	case Package::Type_4: return (out << "type_4");
	case Package::Type_5: return (out << "type_5");
	case Package::Type_6: return (out << "type_6");
	case Package::Type_7: return (out << "type_7");
	case Package::Type_8: return (out << "type_8");
	case Package::Type_9: return (out << "type_9");
	case Package::Type_10: return (out << "type_10");
	}
	return (out);
}

Color colorCast(const std::string& color) {
	if ((int)(color_map.count(color)) == 0) {
		throw std::runtime_error("Invalid data: wrong color type.");
	}
	return color_map.at(color);
}

Freshness freshnessCast(const std::string& freshness) {
	if ((int)(freshness_map.count(freshness)) == 0) {
		throw std::runtime_error("Invalid data: wrong freshness type.");
	}
	return freshness_map.at(freshness);
}

Package packageCast(const std::string& package) {
	if ((int)package_map.count(package) == 0) {
		throw std::runtime_error("Invalid data: wrong package type.");
	}
	return package_map.at(package);
}

bool length_check(const std::string& length) {
	std::stringstream ss(length);
	if (ss.peek() == '.' || ss.peek() == '0') {
		return 1;
	}
	char c = ' ';
	bool point_counter = false;
	for (size_t len = 0; len < length.length(); len++) {
		c = ss.get();
		if (c > '9' || c < '0') {
			if (c != '.') {
				return 1;
			}
			else if (c == '.' && point_counter) {
				return 1;
			}
			else if (c == '.' && !point_counter) {
				point_counter = true;
			}
		}
		
	}
	return 0;
};

bool number_of_sweeets_check(const std::string& number_of_sweeets) {
	std::stringstream ss(number_of_sweeets);
	if (ss.peek() == '0') {
		return 1;
	}
	char c = ' ';

	for (size_t len = 0; len < number_of_sweeets.length(); len++) {
		c = ss.get();
		if (c > '9' || c < '0') {
			return 1;
		}
	}
	return 0;
}

double lengthCast(const std::string& length) {
	if (length_check(length)) {
		throw std::runtime_error("Invalid data: wrong length format.");
	}
	return atof(length.c_str());
}

int numberOfSweeetsCast(const std::string& number_of_sweeets) {
	if (number_of_sweeets_check(number_of_sweeets)) {
		throw std::runtime_error("Invalid data: wrong number of sweeets formart.");
	}
	return atoi(number_of_sweeets.c_str());
}