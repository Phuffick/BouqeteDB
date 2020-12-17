#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

std::string split(std::string& s, const char& sepator);

enum class Freshness {
	one_day = 1, two_days = 2,
	three_days = 3, four_days = 4,
	five_days = 5, six_days = 6,
	seven_days = 7, eight_days = 8,
	nine_days = 9, ten_days = 10,
	more_than_ten = 11
};

enum class Color {
	Red = 1, Blue = 2, Yellow = 3,
	Orange = 4, Pink = 5, Green = 6,
	White = 7, Lilac = 8
};

enum class Package {
	Type_1 = 1, Type_2 = 2, Type_3 = 3,
	Type_4 = 4, Type_5 = 5, Type_6 = 6, Type_7 = 7,
	Type_8 = 8, Type_9 = 9, Type_10 = 10
};

std::ostream& operator << (std::ostream& out, const Color& color);

std::ostream& operator << (std::ostream& out, const Freshness& freshness);

std::ostream& operator << (std::ostream& out, const Package& package);

Color colorCast(const std::string& color);

Freshness freshnessCast(const std::string& freshness);

Package packageCast(const std::string& package);

double lengthCast(const std::string& length);

int numberOfSweeetsCast(const std::string& number_of_sweeets);