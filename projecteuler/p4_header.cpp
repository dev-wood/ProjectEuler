
#include "p4_header.h"

bool checkNumber(int _num, int _digits)
{
	int fac1 = std::pow(10, _digits) - 1;
	int fac2 = 0;
	int min = std::pow(10, _digits - 1);

	if (checkDigits(_num, _digits))
		fac1 = _num;

	if (fac1 > _num)
	{
		if (_num > std::pow(10, _digits - 1))
			fac1 = _num;
		else
		{
			std::cout << "Error: checkNumber(int, int) failed. Wrong _digits value." << std::endl;
			exit(1);
		}
	}
	
	while ((fac1 > fac2) && (fac1 >= min))
	{
		fac2 = getPairFactor(_num, fac1);

		if (checkDigits(fac2, _digits))
			return true;

		fac1--;
	}

	return false;
}

int getPairFactor(int _orig, int _factor1)
{
	if (_orig%_factor1 == 0)
		return (_orig / _factor1);
	else
		return 0;
}

bool checkDigits(int _tarNum, int _digits)
{
	if (_digits < 1)
	{
		std::cout << "Error: checkDigits() failed. Wrong _digits value." << std::endl;
		exit(1);
	}

	int max = std::pow(10, _digits);
	int min = std::pow(10, _digits - 1);

	if (_tarNum >= min && _tarNum < max)
		return true;
	else
		return false;
}

// a-bb-c a-bb-c a-bb-c
// a-bb-c a-c-c a-bb-c 
// a-bb-c a-c-bb a-c-c a-bb-c a-c-bb
// a-bb-c a-c-bb a-c-c a-bb-c a-c-c a-bb-c