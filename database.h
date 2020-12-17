#pragma once
#include <iostream>
#include <exception>
#include <string>
#include "bouquet.h"

class Database {
private:
	Bouquet bouq;

public:
	void AddFlower(const std::string& flower,
		const Freshness& freshness,
		const Color& calyxColor, const double& stemLenght);

	void AddSweet(const std::string& sweetType,
		const Package& packageType, const int& numberOfSweets);

	void DeleteFlower(const std::string& flowerType, const Freshness& freshness,
		const Color& calyxColor, const double& stemLenght);

	void DeleteSweet(const std::string& sweetType,
		const Package& packageType, const int& numberOfSweets);

	bool Delete();

	void Sort();

	void PrintRange(const int& inf, const int& sup);

	void Print();
};