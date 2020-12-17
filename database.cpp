#include "database.h"

void Database::AddFlower(const std::string& flowerType,
	const Freshness& freshness,
	const Color& calyxColor, const double& stemLenght) {

	if (flowerType == "rose") {
		bouq.AddRose(freshness, calyxColor, stemLenght);
	}
	else if (flowerType == "forget_me_not") {
		bouq.AddForgetMeNot(freshness, calyxColor, stemLenght);
	}
	else if (flowerType == "orchid") {
		bouq.AddOrchid(freshness, calyxColor, stemLenght);
	}
	else if (flowerType == "snowdrop") {
		bouq.AddSnowdrop(freshness, calyxColor, stemLenght);
	}
	else if (flowerType == "tulip") {
		bouq.AddTulip(freshness, calyxColor, stemLenght);
	}
	else if (flowerType == "violet") {
		bouq.AddViolet(freshness, calyxColor, stemLenght);
	}
	else {
		throw std::runtime_error("Invalid data: check __Add__");
	}
};

void Database::AddSweet(const std::string& sweetType,
	const Package& packageType, const int& numberOfSweets) {

	if (sweetType == "chocolate") {
		bouq.AddChocolateSweet(packageType, numberOfSweets);
	}
	else if (sweetType == "candy") {
		bouq.AddCandySweet(packageType, numberOfSweets);
	}
	else {
		throw std::runtime_error("Invalid data: check __Add__");
	}
};

void Database::DeleteFlower(const std::string& flowerType, const Freshness& freshness,
	const Color& calyxColor, const double& stemLenght) {

	if (bouq.DeleteFlower(flowerType, freshness, calyxColor, stemLenght)) {
		std::cout << "Flower heve been deleted successfully.\n";
	}
	else {
		std::cout << "Flower wasn't found.\n";
	}
};

void Database::DeleteSweet(const std::string& sweetType,
	const Package& packageType, const int& numberOfSweets) {

	if (bouq.DeleteSweet(sweetType, packageType, numberOfSweets)) {
		std::cout << "Sweet heve been deleted successfully.\n";
	}
	else {
		std::cout << "Sweet wasn't found.\n";
	}
};

bool Database::Delete() {
	bouq.Delete();
	return true;
};

void Database::Sort() {
	bouq.SortBouqete();
};

void Database::PrintRange(const int& inf, const int& sup) {
	bouq.PrintRange(inf, sup);
};

void Database::Print() {
	bouq.Print();
};