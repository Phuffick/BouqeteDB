#pragma once
#include <vector>
#include <algorithm>
#include "namespaces.h"
#include "cost.h"
#include "bouquetParts.h"

class Bouquet {
public:
	void Delete();

	void AddRose(const Freshness& freshness, 
		const Color& calyxColor,
		const double& stemLenght);

	void AddForgetMeNot(const Freshness& freshness,
		const Color& calyxColor, 
		const double& stemLenght);

	void AddOrchid(const Freshness& freshness, 
		const Color& calyxColor, 
		const double& stemLenght);

	void AddSnowdrop(const Freshness& freshness,
		const Color& calyxColor, 
		const double& stemLenght);

	void AddTulip(const Freshness& freshness,
		const Color& calyxColor, 
		const double& stemLenght);

	void AddViolet(const Freshness& freshness,
		const Color& calyxColor, 
		const double& stemLenght);

	void AddChocolateSweet(const Package& packageType, 
		const int& numberOfSweets);

	void AddCandySweet(const Package& packageType,
		const int& numberOfSweets);

	bool DeleteFlower(const std::string& flowerType, 
		const Freshness& freshness, 
		const Color& calyxColor, 
		const double& stemLenght);

	bool DeleteSweet(const std::string& sweet, 
		const Package& packageType, 
		const int& numberOfSweets);

	Cost CalculateBouqeteCost();

	void Print();

	void SortBouqete();

	void PrintRange(const int& inf, 
		const int& sup);

	int GetFlowerNumb();

	int GetSweetNumb();

private:
	std::vector< std::shared_ptr<Flower> > flowers;
	std::vector< std::shared_ptr<Sweet> > sweets;
};