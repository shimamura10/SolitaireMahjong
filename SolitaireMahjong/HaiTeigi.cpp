#include "HaiTeigi.h"
#include <algorithm>

int HaiTeigi::GetZihaiNumber(std::string target)
{
	// 一文字目を大文字にする
	std::transform(target.begin(), target.begin() + 1, target.begin(), ::toupper);

	for (int i = 0; i < 7; i++)
	{
		if (target == zihaiNames[i])
		{
			return i;
		}
	}
	return -1;
}