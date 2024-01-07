#pragma once
#include <vector>
#include "HaiTeigi.h"
#include "Yama.h"
class Tehai : public HaiTeigi
{
public:
	std::vector<std::pair<char, int>> tehaiList = {};
	Tehai(Yama& yama);
	void Display();
	void Discard();
	void Tumo();
private:
	Yama& yama_;
};

