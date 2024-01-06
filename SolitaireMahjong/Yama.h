#pragma once
#include "HaiTeigi.h"
#include <vector>

using namespace std;

class Yama : public HaiTeigi
{
public:
	vector<pair<char, int>> haiList = {};
	Yama();
};

