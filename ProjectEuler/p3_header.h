#include <iostream>

int findLargestPrimeFactor(const int _tarNum);
int breakNumber(int& _tarNum);


// return largest prime factor of _tarNum
int findLargestPrimeFactor(const int _tarNum)
{
	int rtnVal = _tarNum;

	while ( breakNumber(rtnVal) != 1) {
	}

	return rtnVal;
}

// return smallest prime factor of _tarNum
//	return 1 if _tarNum is Prime factor.
int breakNumber(int& _tarNum)
{
	int recurCap = _tarNum / 2 + 1;
	int rtnVal = 1;
	int i = 1;

	while (++i < recurCap) {
		if (_tarNum%i == 0) {
			_tarNum /= i;
			rtnVal = i;
			break;
		}
	}

	return rtnVal;
}