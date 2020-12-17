#pragma once
#include <iostream>
#include "bouquetParts.h"
#include "namespaces.h"
#include "cost.h"

void PrintSweet(const std::string& sweetType, const Package& packageType, 
	const int& numberOfSweets, const Cost& cost);

void PrintFlower(const std::string& flowerType, const Color& calyxColor, 
	const Freshness& freshness, const double& stemLenght, const Cost& cost);


class Sweet {
protected:
	Package packageType;
	int numberOfSweets;
	Cost cost;

public:
	Sweet(const Package& packageType, 
		const int& numberOfSweets);
	int GetNumberOfSweets();
	Package GetPackageType();

	virtual Cost CalculateCost() = 0;
	virtual std::string GetType() = 0;
	virtual void Print() = 0;
	virtual Cost GetCost() = 0;
};


class Chocolate : public Sweet {
public:
	Chocolate(const Package& packageType, 
		const int& numberOfSweets);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};


class Candy : public Sweet {
public:
	Candy(const Package& packageType, 
		const int& numberOfSweets);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};


class Flower {
protected:
	Freshness freshness;
	Color calyxColor;
	double stemLenght;
	Cost cost;

public:
	Flower() { };
	Flower(const Freshness& freshness, const Color& calyxColor, 
		const double& stemLenght);
	double GetStemLenght();
	Freshness GetFreshness();
	Color GetCalyxColor();

	virtual Cost CalculateCost() = 0;
	virtual std::string GetType() = 0;
	virtual void Print() = 0;
	virtual Cost GetCost() = 0;
};


class Rose : public Flower {
public:
	Rose(const Freshness& freshness, const Color& calyxColor,
		const double& stemLenght);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};


class Forget_me_not : public Flower {
public:
	Forget_me_not(const Freshness& freshness, const Color& calyxColor,
		const double& stemLenght);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};


class Orchid : public Flower {
public:
	Orchid(const Freshness& freshness, const Color& calyxColor,
		const double& stemLenght);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};


class Snowdrop : public Flower {
public:
	Snowdrop(const Freshness& freshness, const Color& calyxColor,
		const double& stemLenght);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};


class Tulip : public Flower {
public:
	Tulip(const Freshness& freshness, const Color& calyxColor,
		const double& stemLenght);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};


class Violet : public Flower {
public:
	Violet(const Freshness& freshness, const Color& calyxColor,
		const double& stemLenght);

	Cost CalculateCost();

	Cost GetCost();

	std::string GetType();

	void Print();
};

bool operator < (const std::shared_ptr<Flower>& lhs, 
	const std::shared_ptr<Flower>& rhs);

template <typename Collection>
void sortB(Collection& flowers) {
	std::shared_ptr<Flower> temp;
	for (size_t i = 1; i < flowers.size(); i++) {
		for (size_t j = i; (j > 0) && (flowers[j] < flowers[j - 1]); --j) {
			temp = flowers[j];
			flowers[j] = flowers[j - 1];
			flowers[j - 1] = temp;
		}
	}
};