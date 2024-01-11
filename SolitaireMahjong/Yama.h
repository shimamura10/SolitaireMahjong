#pragma once
#include "HaiTeigi.h"
#include "Hai.h"
#include <vector>

using namespace std;

class Yama : public HaiTeigi
{
public:
	vector<Hai> haiList = {};
	Yama();
};

