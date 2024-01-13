#include "Tehai.h"
#include "Hai.h"
#include <iostream>
#include <regex>
#include <unordered_map>
#include <algorithm>
#include <map>

Tehai::Tehai(Yama& yama) : yama_(yama)
{
	for (int i = 0; i < 14; i++)
	{
		Tumo();
	}
}

/// <summary>
/// Žè”v‚ð•\Ž¦‚·‚é
/// </summary>
void Tehai::Display()
{
	std::sort(tehaiList.begin(), tehaiList.end());
	for (auto& kind : Hai::kindList)
	{
		string result = "";
		for (auto& hai : tehaiList)
		{
			if (kind == hai.kind_)
			{
				result += hai.NumberToDisplayName();
			}
		}
		if (result == "") { continue; }
		if (kind != Hai::zihaiKind)
		{
			cout << kind;
		}
		cout << result << " ";
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
			auto target = Hai(std::string(1,input[0]), static_cast<int>(input[1] - '0') - 1);
			auto itr = std::find(std::begin(this->tehaiList), std::end(this->tehaiList), target);
			if (itr == this->tehaiList.end())
			{
				cout << "Žw’è‚³‚ê‚½”v‚ªŽè”v‚É‚ ‚è‚Ü‚¹‚ñ" << endl;
			}
			else {
				tehaiList.erase(itr);
			}
		}
		else if (std::regex_match(input, zihai)){
			int index = GetZihaiNumber(input);
			auto target = Hai("z", index);
			auto itr = std::find(std::begin(this->tehaiList), std::end(this->tehaiList), target);
			if (itr == this->tehaiList.end())
			{
				cout << "Žw’è‚³‚ê‚½”v‚ªŽè”v‚É‚ ‚è‚Ü‚¹‚ñ" << endl;
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

/// <summary>
/// Žè”v‚ª‚ ‚ª‚èŒ`‚É‚È‚Á‚Ä‚¢‚é‚©”»’è‚·‚é
/// </summary>
/// <returns>‚ ‚ª‚è:true, ‚ ‚ª‚Á‚Ä‚È‚¢:false</returns>
bool Tehai::JudgeAgari()
{
	std::sort(tehaiList.begin(), tehaiList.end());
	vector<Hai> jantos;
	for (auto itr = tehaiList.begin(); itr < tehaiList.end()-1; itr++)
	{
		if (*itr == *(itr + 1))
		{
			jantos.emplace_back(*itr);
			itr++; 
			while (itr < tehaiList.end()-1 && *itr == *(itr+1))
			{
				itr++;
			}
		}
	}
	for (auto& janto : jantos)
	{
		vector<Hai> copiedTehai;
		int cnt = 2;
		for (auto& tehai : tehaiList)
		{
			if (cnt > 0 && tehai == janto)
			{
				cnt -= 1;
				continue;
			}
			copiedTehai.emplace_back(Hai(tehai.kind_, tehai.number_));
		}
		while (copiedTehai.size() > 0)
		{
			Hai& initial = copiedTehai[0];
			//cout << "count of " << initial.kind_ << initial.number_ << " is " << count(copiedTehai.begin(), copiedTehai.end(), initial) << endl;
			// Žq‚ð’T‚µ‚ÄÁ‚·
			if (count(copiedTehai.begin(), copiedTehai.end(), initial) >= 3)
			{
				for (int i = 0; i < 3; i++)
				{
					copiedTehai.erase(find(copiedTehai.begin(), copiedTehai.end(), initial));
				}
				continue;
			}
			if (initial.IsZihai())
			{
				break;
			}
			// Žq‚ª‚È‚¯‚ê‚Î‡Žq‚ð’T‚µ‚ÄÁ‚·
			Hai next = Hai(initial.kind_, initial.number_+1);
			Hai nextnext = Hai(initial.kind_, initial.number_+2);
			if (count(copiedTehai.begin(), copiedTehai.end(), next) > 0 && count(copiedTehai.begin(), copiedTehai.end(), nextnext) > 0)
			{
				copiedTehai.erase(find(copiedTehai.begin(), copiedTehai.end(), initial));
				copiedTehai.erase(find(copiedTehai.begin(), copiedTehai.end(), next));
				copiedTehai.erase(find(copiedTehai.begin(), copiedTehai.end(), nextnext));
				continue;
			}
			break;
		}
		if (copiedTehai.size() == 0)
		{
			return true;
		}
	}
	return false;
}

bool Tehai::JudgeTenpai()
{
	if (tehaiList.size() != 13)
	{
		return false;
	}

	for (auto& hai : Hai::allHaiList)
	{
		tehaiList.emplace_back(hai);
		if (this->JudgeAgari())
		{
			tehaiList.erase(find(tehaiList.begin(), tehaiList.end(), hai));
			return true;
		}
		tehaiList.erase(find(tehaiList.begin(), tehaiList.end(), hai));
	}
	return false;
}