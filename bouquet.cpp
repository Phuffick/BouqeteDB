#include "bouquet.h"

void Bouquet::Delete() {
	if (flowers.size() != 0 || sweets.size() != 0) {
		flowers.clear();
		sweets.clear();
	}
	else {
		std::cout << "Already clear.\n";
	}
};

void Bouquet::AddRose(const Freshness& freshness,
	const Color& calyxColor,
	const double& stemLenght) {
	flowers.push_back(std::make_shared<Rose>(freshness, calyxColor, stemLenght));
};

void Bouquet::AddForgetMeNot(const Freshness& freshness,
	const Color& calyxColor,
	const double& stemLenght) {
	flowers.push_back(std::make_shared <Forget_me_not>(freshness, calyxColor, stemLenght));
};

void Bouquet::AddOrchid(const Freshness& freshness,
	const Color& calyxColor,
	const double& stemLenght) {
	flowers.push_back(std::make_shared <Orchid>(freshness, calyxColor, stemLenght));
};

void Bouquet::AddSnowdrop(const Freshness& freshness,
	const Color& calyxColor,
	const double& stemLenght) {
	flowers.push_back(std::make_shared <Snowdrop>(freshness, calyxColor, stemLenght));
};

void Bouquet::AddTulip(const Freshness& freshness,
	const Color& calyxColor,
	const double& stemLenght) {
	flowers.push_back(std::make_shared <Tulip>(freshness, calyxColor, stemLenght));
};

void Bouquet::AddViolet(const Freshness& freshness,
	const Color& calyxColor,
	const double& stemLenght) {
	flowers.push_back(std::make_shared <Violet>(freshness, calyxColor, stemLenght));
};

void Bouquet::AddChocolateSweet(const Package& packageType, 
	const int& numberOfSweets) {
	sweets.push_back(std::make_shared <Chocolate>(packageType, 
												 numberOfSweets));
};

void Bouquet::AddCandySweet(const Package& packageType, 
	const int& numberOfSweets) {
	sweets.push_back(std::make_shared <Candy>(packageType, numberOfSweets));
};

bool Bouquet::DeleteFlower(const std::string& flower_type, 
	const Freshness& freshness_temp,
	const Color& calyx_color_temp, 
	const double& stem_lenght_temp) {
	int i = 0;
	for (auto& flower : flowers) {
		if ((flower->GetType() == flower_type) 
			&& flower->GetFreshness() == freshness_temp 
			&& flower->GetCalyxColor() == calyx_color_temp 
			&& flower->GetStemLenght() == stem_lenght_temp) {

			flowers.erase(begin(flowers) + i, begin(flowers) + i + 1);
			return 1;
		}
		i++;
	}

	return 0;
};

bool Bouquet::DeleteSweet(const std::string& sweetType, 
	const Package& packageType,
	const int& numberOfSweets) {
	int i = 0;
	for (auto& sweet : sweets) {
		if ((sweet->GetType() == sweetType) 
			&& sweet->GetPackageType() == packageType 
			&& sweet->GetNumberOfSweets() == numberOfSweets) {

			sweets.erase(begin(sweets) + i, begin(sweets) + i + 1);
			return 1;
		}
		i++;
	}

	return 0;
};

Cost Bouquet::CalculateBouqeteCost() {
	Cost cost;

	for (auto& flower : flowers) {
		cost = flower->GetCost() + cost;
	}

	for (auto& sweet : sweets) {
		cost = sweet->GetCost() + cost;
	}

	return cost;
};

void Bouquet::Print() {
	if (flowers.size() != 0) {
		std::cout << "The bouquet consists of the following flowers: \n";
		for (auto& flower : flowers) {
			flower->Print();
			std::cout << '\n';
		}
	}

	if (sweets.size() != 0) {
		std::cout << "And in addition: \n";
		for (auto& sweet : sweets) {
			sweet->Print();
			std::cout << '\n';
		}
	}

	if (flowers.size() != 0 
		|| sweets.size() != 0) {
		std::cout << "With total cost " 
			<< CalculateBouqeteCost() << '\n';
	}
	else {
		std::cout << "There is no one flower or sweet.\n";
	}
};

void Bouquet::SortBouqete() {
	sortB(flowers);
};

void Bouquet::PrintRange(const int& inf, 
	const int& sup) {

	if (flowers.size() == 0) {
		std::cout << "There is no one flower.\n";
		return;
	}

	int flow = 0;
	for (auto& flower : flowers) {
		if ((inf <= flower->GetStemLenght()) && (flower->GetStemLenght() <= sup)) {
			flower->Print();
			std::cout << '\n';
			flow++;
		}
	}
	
	if (flow == 0) {
		std::cout << "There is no one flower with stem lenght in range [" 
			<< inf << "," << sup << "]" << '\n';
	}
};

int Bouquet::GetFlowerNumb() {
	return flowers.size();
};

int Bouquet::GetSweetNumb() {
	return sweets.size();
};