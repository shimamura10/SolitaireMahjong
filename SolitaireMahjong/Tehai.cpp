#include "Tehai.h"
#include <iostream>
Tehai::Tehai(Yama& yama) : yama_(yama)
{
	for (int i = 0; i < 14; i++)
	{
		this->tehaiList.emplace_back(yama_.haiList.back());
		yama_.haiList.pop_back();
	}
}

void Tehai::Display()
{
	std::string result = "";
	for (auto kind : kinds)
	{
		std::string oneKindList = "";
		for (auto hai : this->tehaiList)
		{
			if (kind == hai.first)
			{
				if (kind == kinds[3])
				{
					oneKindList += zihaiNames[hai.second];
				}
				else
				{
					oneKindList += std::to_string(hai.second+1);
				}
			}
		}
		if (oneKindList != "")
		{
			if (kind != kinds[3])
			{
				cout << kind;
			}
			cout << oneKindList << " ";
		}
	}
	cout << endl;
}