#include "p8_header.h"

NumberSeries::NumberSeries(const std::string & _fileName, int _szSeries, int _szWnd)
{
	readFile(_fileName, _szSeries);
	
	inWndLastIt = arr.cbegin();

	if (_szSeries < _szWnd) {
		std::cout << "Size of window is larger than size of series. Program terminated." << std::endl;
		exit(1);
	}

	inWndLastIt += _szWnd;		//rev 확인할 것.

	//rev 계속 작성..

}

NumberSeries::~NumberSeries()
{
}

std::vector<int>& NumberSeries::get_arr()
{
	return arr;
}

void NumberSeries::readFile(const std::string & _fileName, int _szSeries)
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
