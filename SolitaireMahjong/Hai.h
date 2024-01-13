#pragma once
#include <string>
#include <unordered_map>
class Hai
{
public:
	static std::string kindList[4];
	static std::string zihaiNames[7];
	static std::string suhaiNames[9];
	static std::unordered_map<std::string, int> kindOrder;
	static Hai allHaiList[34];
	static std::string zihaiKind;

	std::string kind_;
	int number_;
	Hai(std::string kind, int number) : kind_(kind), number_(number) {};
	bool IsZihai();
	std::string NumberToDisplayName();
	bool operator==(const Hai& other) const;
	bool operator<(const Hai& other) const;
};