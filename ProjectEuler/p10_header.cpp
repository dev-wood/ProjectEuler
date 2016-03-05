#include "p10_header.h"

bool Prime::primeCheck(int _nextCandidate)
{
	for (auto el : arr)
	{
		if (_nextCandidate % el==0) {
			return false;
		}
	}

	return true;
}

int Prime::getNextPrimeInArr()
{
	int tmpVal = arr.back();

	while (1)
	{
		tmpVal++;
		if (primeCheck(tmpVal))
		{
			return tmpVal;
		}
	}
}

void Prime::setPrimeArrTo(int _n)
{
	while (arr.size() <= _n)
	{
		arr.push_back(getNextPrimeInArr());
	}
	return;
}

void Prime::setPrimeArrLessThan(int _val)
{
	int tmpVal;

	while (1) {
		tmpVal = getNextPrimeInArr();
		if (tmpVal < _val) {
			arr.push_back(tmpVal);
		}
		else {
			break;
		}
	}

	return;
}



Prime::Prime()
{
	arr.reserve(100);
	arr.push_back(2);
}

Prime::Prime(int _lessThan)
{
	arr.reserve(100);
	arr.push_back(2);
	//Prime();		// error. 한 생성자 내에서 default constructor를 불러서 초기화를 시키고 싶을 땐 어떻게..?

	auto lastEl = arr.back();

	if(lastEl < _lessThan)	
		setPrimeArrLessThan(_lessThan);

	return;
}

int Prime::operator[](int _n)
{
	if (_n >= arr.size()) {
		// get more prime
		setPrimeArrTo(_n);
	}

	return arr[_n];
}

void Prime::print()
{
	for (auto el : arr)
		std::cout << el << ' ';
	std::cout << std::endl;
	std::cout << "The number of primes: " << arr.size() << std::endl;
}

std::vector<int>::const_iterator Prime::begin()
{
	return arr.cbegin();
}

std::vector<int>::const_iterator Prime::end()
{
	return arr.cend();
}
