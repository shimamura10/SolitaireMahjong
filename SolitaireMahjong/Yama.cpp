#include "Yama.h"
#include <algorithm>
#include <numeric>
#include <random>

Yama::Yama()
{
	// �R�̃��X�g�����
	// �v��pari<���:char�A��:int>
	for (auto kind : kinds)
	{
		if (kind == kinds[3])
		{
			for (auto i = 0; i < 7; i++)
			{
				for (auto j = 0; j < 4; j++)
				{
					this->haiList.emplace_back(std::make_pair(kind, i));
				}
			}
		}
		else {
			for (auto i = 0; i < 9; i++)
			{
				for (auto j = 0; j < 4; j++)
				{
					this->haiList.emplace_back(std::make_pair(kind, i));
				}
			}
		}
	}

	// �R���V���b�t��
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::shuffle(this->haiList.begin(), this->haiList.end(), engine);
}
