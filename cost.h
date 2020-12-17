#pragma once
#include <iostream>
#include <string>

class Cost {
private:
	double cost;
	int dollars;
	int cents;

public:
	Cost();

	explicit Cost(const double& cost);

	int GetDollars() const;

	int GetCents() const;

	friend Cost operator + (const Cost& lhs, const Cost& rhs);
	friend std::ostream& operator << (std::ostream& out, const Cost& cost);
};