#include "bouquetParts.h"

void PrintSweet(const std::string& sweetType, const Package& packageType, 
	const int& numberOfSweets, const Cost& cost) {

	std::cout << sweetType << " sweets in " << packageType <<
		" package, " << numberOfSweets << " pieces in package with cost " << cost << ".";
}

void PrintFlower(const std::string& flower_type, const Color& calyxColor, 
	const Freshness& freshness, const double& stemLenght, const Cost& cost) {
	
	if ((int)freshness != 11) {
		std::cout << flower_type << " with " << calyxColor << " calyx, " << freshness
			<< " day(s) freshnes, " << stemLenght << " cm stem length and cost " << cost << ".";
	}
	else {
		std::cout << flower_type << " with " << calyxColor
			<< " calyx, more than ten days freshnes, " << stemLenght << " cm stem length and cost " << cost << ".";
	}
}


Sweet::Sweet(const Package& packageType, const int& numberOfSweets) {
	this->packageType = packageType;
	this->numberOfSweets = numberOfSweets;
}

int Sweet::GetNumberOfSweets() {
	return this->numberOfSweets;
}

Package Sweet::GetPackageType() {
	return this->packageType;
}


Chocolate::Chocolate(const Package& packageType, const int& numberOfSweets)
	: Sweet(packageType, numberOfSweets) {
	this->cost = CalculateCost();
}

Cost Chocolate::CalculateCost() {
	return Cost((int)packageType * 0.10 
		+ numberOfSweets * 0.20);
}

Cost Chocolate::GetCost() {
	return cost;
}

std::string Chocolate::GetType() {
	return "Chocolate";
}

void Chocolate::Print() {
	PrintSweet("Chocolate", GetPackageType(), 
		GetNumberOfSweets(), GetCost());
}


Candy::Candy(const Package& packageType, const int& numberOfSweets)
	: Sweet(packageType, numberOfSweets) {
	this->cost = CalculateCost();
}

Cost Candy::CalculateCost() {
	return Cost((int)packageType * 0.05 
		+ numberOfSweets * 0.10);
}

Cost Candy::GetCost() {
	return cost;
}

std::string Candy::GetType() {
	return "Candy";
}

void Candy::Print() {
	PrintSweet("Candy", GetPackageType(), 
		GetNumberOfSweets(), GetCost());
}


Flower::Flower(const Freshness& freshness, 
	const Color& calyxColor, const double& stemLenght) {
	this->freshness = freshness;
	this->calyxColor = calyxColor;
	this->stemLenght = stemLenght;
	this->cost = Cost(0.);
}

double Flower::GetStemLenght() {
	return stemLenght;
}

Freshness Flower::GetFreshness() {
	return freshness;
}

Color Flower::GetCalyxColor() {
	return calyxColor;
}


Rose::Rose(const Freshness& freshness, const Color& calyxColor, 
	const double& stemLenght) : Flower(freshness, calyxColor, stemLenght) {
	this->cost = CalculateCost();
}

Cost Rose::CalculateCost() {
	return Cost((int)freshness * 0.20 
		+ (int)calyxColor * 0.1 + (int)stemLenght * 0.14);
}

Cost Rose::GetCost() {
	return cost;
}

std::string Rose::GetType() {
	return "rose";
}

void Rose::Print() {
	PrintFlower("Rose", GetCalyxColor(), 
		GetFreshness(), GetStemLenght(), GetCost());
};


Forget_me_not::Forget_me_not(const Freshness& freshness, const Color& calyxColor, 
	const double& stemLenght) : Flower(freshness, calyxColor, stemLenght) {
	this->cost = CalculateCost();
}

Cost Forget_me_not::CalculateCost() {
	return Cost((int)freshness * 0.3 
		+ (int)calyxColor * 0.15 + (int)stemLenght * 0.17);
}

Cost Forget_me_not::GetCost() {
	return cost;
}

std::string Forget_me_not::GetType() {
	return "forget_me_not";
}

void Forget_me_not::Print() {
	PrintFlower("Forget me not", GetCalyxColor(), 
		GetFreshness(), GetStemLenght(), GetCost());
};



Orchid::Orchid(const Freshness& freshness, const Color& calyxColor,
	const double& stemLenght) : Flower(freshness, calyxColor, stemLenght) {
	this->cost = CalculateCost();
}

Cost Orchid::CalculateCost() {
	return Cost((int)freshness * 0.30 
		+ (int)calyxColor * 0.15 + (int)stemLenght * 0.19);
}

Cost Orchid::GetCost() {
	return cost;
}

std::string Orchid::GetType() {
	return "orchid";
}

void Orchid::Print() {
	PrintFlower("Orchid", GetCalyxColor(), 
		GetFreshness(), GetStemLenght(), GetCost());
}


Snowdrop::Snowdrop(const Freshness& freshness, const Color& calyxColor,
	const double& stemLenght) : Flower(freshness, calyxColor, stemLenght) {
	this->cost = CalculateCost();
}

Cost Snowdrop::CalculateCost() {
	return Cost((int)freshness * 0.34
		+ (int)calyxColor * 0.25 + (int)stemLenght * 0.29);
}

Cost Snowdrop::GetCost() {
	return cost;
}

std::string Snowdrop::GetType() {
	return "snowdrop";
}

void Snowdrop::Print() {
	PrintFlower("Snowdrop", GetCalyxColor(), 
		GetFreshness(), GetStemLenght(), GetCost());
};


Tulip::Tulip(const Freshness& freshness, const Color& calyxColor,
	const double& stemLenght) : Flower(freshness, calyxColor, stemLenght) {
	this->cost = CalculateCost();
}

Cost Tulip::CalculateCost() {
	return Cost((int)freshness * 0.24 
		+ (int)calyxColor * 0.12 + (int)stemLenght * 0.11);
}

Cost Tulip::GetCost() {
	return cost;
}

std::string Tulip::GetType() {
	return "tulip";
}

void Tulip::Print() {
	PrintFlower("Tulip", GetCalyxColor(), 
		GetFreshness(), GetStemLenght(), GetCost());
};


Violet::Violet(const Freshness& freshness, const Color& calyxColor,
	const double& stemLenght) : Flower(freshness, calyxColor, stemLenght) {
	this->cost = CalculateCost();
}

Cost Violet::CalculateCost() {
	return Cost((int)freshness * 0.26 
		+ (int)calyxColor * 0.21 + (int)stemLenght * 0.15);
}

Cost Violet::GetCost() {
	return cost;
}

std::string Violet::GetType() {
	return "violet";
}

void Violet::Print() {
	PrintFlower("Violet", GetCalyxColor(),
		GetFreshness(), GetStemLenght(), GetCost());
}; 

bool operator < (const std::shared_ptr<Flower>& lhs, 
	const std::shared_ptr<Flower>& rhs) {
	return lhs->GetFreshness() < rhs->GetFreshness();
};