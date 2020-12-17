#include "cost.h"

Cost::Cost() {
	this->cost = 0.;
	this->dollars = 0;
	this->cents = 0;
}

Cost::Cost(const double& cost) {
	this->cost = cost;

	std::string costInStr = std::to_string(cost);
	std::string dollarsInStr = "";
	std::string centsInStr = "";

	bool flag = true;
	for (const char& number : costInStr) {
		if (number != '.' && flag) {
			dollarsInStr += number;
		}
		else {
			centsInStr += number;
			flag = false;
		}
	}

	centsInStr.erase(begin(centsInStr), begin(centsInStr) + 1);
	dollars = atoi(dollarsInStr.c_str());
	cents = atoi(centsInStr.c_str());
}

int Cost::GetCents() const {
	return cents;
}

int Cost::GetDollars() const {
	return dollars;
}

std::ostream& operator << (std::ostream& out, const Cost& cost) {
	out << cost.GetDollars() << "," << cost.GetCents() << "$";
	return out;
}

Cost operator + (const Cost& lhs, const Cost& rhs) {
	return Cost(lhs.cost + rhs.cost);
}