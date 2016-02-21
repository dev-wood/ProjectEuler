#include "p8_header.h"

void NumberSeries::readFile(const std::string & _fileName)
{
	std::fstream fstrm;
	fstrm.open(_fileName, std::fstream::in);

	arr.reserve(_szSeries);

	int i;
	int imin = static_cast<int>('0');
	int imax = static_cast<int>('9');
	char ch;
	while (fstrm.get(ch))
	{
		i = static_cast<int>(ch);

		if (i > imax || i < imin)
			std::cout << "Wrong i value input" << std::endl;
		else
			arr.push_back(i - imin);
	}

	fstrm.close();
}

bool NumberSeries::slide(int _steps)
{
	for (int i = 0; i < _steps; i++) {
		cWndRevIt++;
		if (cWndRevIt == arr.cend())
			return false;
	}

	return true;
}

NumberSeries::NumberSeries() : maxProduct(0), curProduct(0), windowSize(0)
{
	cWndRevIt = arr.cbegin();
}

// 
NumberSeries::NumberSeries(const char * _fileName, int _sizeOfSeries, int _offset) : windowSize(_offset)
{
	arr.reserve(_sizeOfSeries);
	readFile(_fileName);

	if (arr.size() < windowSize)
	{
		std::cout << "Size of number series is smaller than window size. Object creation failed." << std::endl;
		exit(1);
	}
	
	// pose cWndRevIt
	cWndRevIt = arr.cbegin() + (windowSize - 1);

	// set curProduct & maxProduct
	curProduct = 1;
	auto it = arr.cbegin();
	while (it != cWndRevIt) {
		curProduct *= *it;
		it++;
	}
	curProduct *= *it;
	maxProduct = curProduct;
}

NumberSeries::~NumberSeries()
{
}

std::vector<int>& NumberSeries::get_arr()
{
	return arr;
}

int NumberSeries::getMaxProduct()
{
	// slide window
	while (slide(1) != false)
	{
		// get current product value
		if (curProduct == 0)
		{
			auto it = cWndRevIt - windowSize;
			if ((*it) == 0) {
				curProduct = 1;
				while (it++ != cWndRevIt) {
					curProduct *= (*it);
				}
			}
		}
		else
		{
			auto it = cWndRevIt - windowSize;
			curProduct = curProduct / (*it) * (*cWndRevIt);
		}

		if (maxProduct < curProduct) {
			maxProduct = curProduct;

			auto it = cWndRevIt - windowSize + 1;
			while (it != cWndRevIt) {
				std::cout << *it << " * ";
				it++;
			}
			std::cout << *it << std::endl;
		}
	}

	return maxProduct;
}
