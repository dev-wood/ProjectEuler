#include "p7_header.h"

std::vector<int> Prime::arr({ 2 });
//Prime::arr.reserve(100);		// error

Prime::Prime()
{
}

bool Prime::primeCheck(int _num)
{
	bool ret = true;
	for (auto it : arr)
	{
		if (_num % it == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

int Prime::getNthNumber(int _nth)
{
	//while (arr.size() < _nth)
	//{
	//	
	//}
	for (int tmp = arr.back() + 1; arr.size() < _nth; tmp++) {		// in case of _nth Prime doesn't get
		if (primeCheck(tmp))	// error: "비정적 멤버 참조는 특정 개체에 상대적이어야 합니다."
			arr.push_back(tmp);
	}

	return arr[_nth - 1];
}

void Prime::print()
{
	for (auto it : arr)
		std::cout << it << " ";

	std::cout << std::endl;
}