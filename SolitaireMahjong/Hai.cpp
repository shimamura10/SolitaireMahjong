#include "Hai.h"

std::string Hai::kindList[4] = { "w", "p", "s", "z" };
std::string Hai::zihaiNames[7] = { "Ea", "Sa", "We", "No", "Wh", "Gr", "Re" };
std::string Hai::suhaiNames[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
std::string Hai::zihaiKind = "z";
Hai Hai::allHaiList[34] = {
	Hai("w", 0), Hai("w", 1), Hai("w", 2), Hai("w", 3), Hai("w", 4), Hai("w", 5), Hai("w", 6), Hai("w", 7), Hai("w", 8),
	Hai("s", 0), Hai("s", 1), Hai("s", 2), Hai("s", 3), Hai("s", 4), Hai("s", 5), Hai("s", 6), Hai("s", 7), Hai("s", 8),
	Hai("p", 0), Hai("p", 1), Hai("p", 2), Hai("p", 3), Hai("p", 4), Hai("p", 5), Hai("p", 6), Hai("p", 7), Hai("p", 8),
	Hai("z", 0), Hai("z", 1), Hai("z", 2), Hai("z", 3), Hai("z", 4), Hai("z", 5), Hai("z", 6)
};
std::unordered_map<std::string, int> Hai::kindOrder = { {"w", 0}, {"p", 1}, {"s", 2}, {"z", 3} };

bool Hai::IsZihai()
{
	if (kind_ == kindList[3])
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Hai::NumberToDisplayName()
{
	if (this->IsZihai())
	{
		return Hai::zihaiNames[number_];
	} 
	else
	{
		return Hai::suhaiNames[number_];
	}
}

bool Hai::operator==(const Hai& other) const {
	if (this->kind_ == other.kind_ && this->number_ == other.number_)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Hai::operator<(const Hai& other) const {
	if (this->kind_ != other.kind_)
	{
		return kindOrder[this->kind_] < kindOrder[other.kind_];
	}
	else {
		return this->number_ < other.number_;
	}
}