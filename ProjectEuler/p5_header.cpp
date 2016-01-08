
#include "p5_header.h"

std::vector<std::pair<int, int>> factorization(int _number)
{
	std::vector<std::pair<int, int>> factList;
	factList.reserve(10);

	int factor = 2;

	while (_number != 1)
	{
		std::pair<int, int> factPair(factor, 0);

		while (_number%factor == 0)
		{
			_number /= factor;
			factPair.second++;
		}
		
		factor++;

		if (factPair.second != 0)
			factList.push_back(factPair);
	}

	factList.shrink_to_fit();

	return factList;
}

int getNumber(int _number)
{
	std::list<std::pair<int, int>> rtnNum;
	
	int i = 1;
	
	while (i <= _number)
	{
		std::vector<std::pair<int, int>> tmpNum = factorization(i);
		auto tmpIt = tmpNum.cbegin();
		auto rtnIt = rtnNum.begin();

		for (; (tmpIt != tmpNum.cend()) && (rtnIt != rtnNum.end()); )
		{
			if (tmpIt->first == rtnIt->first) {
				if (tmpIt->second > rtnIt->second)
					rtnIt->second = tmpIt->second;
				
				tmpIt++;
				rtnIt++;
			}
			else if (tmpIt->first < rtnIt->first) {
				rtnNum.insert(rtnIt, *tmpIt);		//? std::insert() 가 아니라 std::list의 insert() 멤버함수 사용.. 가능? 가능
				tmpIt++;
			}
			else {
				rtnIt++;
			}
		}

		if (rtnIt == rtnNum.end())
		{
			rtnNum.insert(rtnIt, tmpIt, tmpNum.cend());
		}

		i++;
	}

	int rtnVal = 1;

	for (auto it : rtnNum) 
	{
		rtnVal *= std::pow(it.first, it.second);
	}

	return rtnVal;
}