#include "Tehai.h"
#include <iostream>
#include <regex>

Tehai::Tehai(Yama& yama) : yama_(yama)
{
	for (int i = 0; i < 14; i++)
	{
		Tumo();
	}
}

void Tehai::Display()
{
	for (auto kind : kinds)
	{
		std::vector<string> result = {};
		for (auto hai : this->tehaiList)
		{
			if (kind == hai.first)
			{
				if (kind == kinds[3])
				{
					//oneKindList += zihaiNames[hai.second];
					result.emplace_back(zihaiNames[hai.second]);
				}
				else
				{
					//oneKindList += std::to_string(hai.second+1);
					result.emplace_back(std::to_string(hai.second + 1));
				}
			}
		}
		if (result.size() > 0)
		{
			if (kind != kinds[3])
			{
				cout << kind;
			}

			std::sort(result.begin(), result.end());
			for (auto& hai : result)
			{
				cout << hai;
			}
			cout << " ";
		}
	}
	cout << endl;
}

void Tehai::Discard()
{
	while (this->tehaiList.size() > 13)
	{
		std::string input;
		cin >> input;
		int i = static_cast<int>(input[1]);
		std::regex suhai("[wps][1-9]");
		std::regex zihai("[E|e]a|[S|s]a|[N|n]o|[W|w]e|[W|w]h|[G|g]r|[R|r]e");
		if (std::regex_match(input, suhai))
		{
			auto target = std::make_pair(input[0], static_cast<int>(input[1] - '0') - 1);
			auto itr = std::find(std::begin(this->tehaiList), std::end(this->tehaiList), target);
			if (itr == this->tehaiList.end())
			{
				cout << "w’è‚³‚ê‚½”v‚ªè”v‚É‚ ‚è‚Ü‚¹‚ñ" << endl;
			}
			else {
				tehaiList.erase(itr);
			}
		}
		else if (std::regex_match(input, zihai)){
			int index = GetZihaiNumber(input);
			auto itr = std::find(std::begin(this->tehaiList), std::end(this->tehaiList), std::make_pair(kinds[3], index));
			if (itr == this->tehaiList.end())
			{
				cout << "w’è‚³‚ê‚½”v‚ªè”v‚É‚ ‚è‚Ü‚¹‚ñ" << endl;
			}
			else {
				tehaiList.erase(itr);
			}
		}
		else {
			cout << "“ü—ÍƒtƒH[ƒ}ƒbƒg‚ªŠÔˆá‚Á‚Ä‚¢‚Ü‚·" << endl;
		}
	}
}

void Tehai::Tumo()
{
	this->tehaiList.emplace_back(yama_.haiList.back());
	yama_.haiList.pop_back();
}