#include "p8_header.h"

void NumberSeries::readFile(const std::string & _fileName)
{
	std::fstream fstrm;
	fstrm.open(_fileName, std::fstream::in);

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

NumberSeries::NumberSeries() : maxProduct(0), curProduct(0), windowSize(0)
{
	cWRevItPos = arr.cbegin();
}

// 
NumberSeries::NumberSeries(const char * _fileName, int _sizeOfSeries, int _offset) : windowSize(_offset)
{
	arr.reserve(_sizeOfSeries);
	readFile(_fileName);
	cWRevItPos = arr.cbegin();	//rev 

	if (!objErrorTest()) {
		std::cout << "Object creation failed." << std::endl;
		exit(1);
	}

	if (outOfRangeWindowTest(cItPos, windowSize))	//rev
	{
		curProduct = 1;
		for (auto it = cItPos; cItPos < cItPos + windowSize; it++)
			curProduct *= *it;
		maxProduct = curProduct;
	}
	else
	{
		std::cout << ""
	}

}

NumberSeries::~NumberSeries()
{
}

std::vector<int>& NumberSeries::get_arr()
{
	return arr;
}
