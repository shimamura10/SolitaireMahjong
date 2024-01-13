#pragma once
#include <vector>
#include "HaiTeigi.h"
#include "Hai.h"
#include "Yama.h"
class Tehai : public HaiTeigi
{
public:
	std::vector<Hai> tehaiList = {};
	Tehai(Yama& yama);
	void Display();
	void Discard();
	void Tumo();
	bool JudgeAgari();
	bool JudgeTenpai();
private:
	Yama& yama_;
};

