#include "p8_header.h"

NumberSeries::NumberSeries()
{
}

NumberSeries::NumberSeries(int _arrSize)
{
	arr.reserve(_arrSize);
}

NumberSeries::~NumberSeries()
{
}

std::vector<int>& NumberSeries::get_arr()
{
	return arr;
}

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
