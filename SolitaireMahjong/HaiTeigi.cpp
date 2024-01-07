#include "HaiTeigi.h"
#include <algorithm>

int HaiTeigi::GetZihaiNumber(std::string target)
{
	// ˆê•¶Žš–Ú‚ð‘å•¶Žš‚É‚·‚é
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