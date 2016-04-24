#include "p12_header.h"

TriangleNumber::TriangleNumber() :_lastAddedNum(1)
{
	_arr.push_back(1);
}

TriangleNumber::TriangleNumber(my::uint nth) : TriangleNumber()
{
	for (my::uint i = 0; i < nth - 1; ++i)
		getNextNumber();
}

my::uint TriangleNumber::operator[](my::uint idx)
{
	while (idx >= _arr.size()) {
		getNextNumber();
	}

	return _arr.at(idx);
}

my::uint TriangleNumber::getNextNumber()
{
	_arr.push_back(_arr.back() + ++_lastAddedNum);

	return _arr.back();
}

void TriangleNumber::print()
{
	for (auto it : _arr)
		std::cout << it << " ";
	std::cout << std::endl;
	return;
}

my::uint TriangleNumber::get_lastAddedNum()
{
	return _lastAddedNum;
}

my::uint Division::_tarNum = 0;		//rev
my::uint Division::_numOfDiv = 0;
my::uint Division::_curDivisor = 0;

my::uint Division::getNumOfDevisor(my::uint num)
{
	// clearing & initiating
	_init();
	_tarNum = num;

	while(1)
	{
		if (_tarNum%_curDivisor == 0)
			_numOfDiv++;

		if (_quittingCheck())
			break;

		_curDivisor++;
	}

	// double the number of division
	if (_curDivisor*_curDivisor == _tarNum)
		_numOfDiv = _numOfDiv * 2 - 1;
	else
		_numOfDiv *= 2;

	return _numOfDiv;
}

void Division::_init()
{
	_tarNum = 0;
	_numOfDiv = 0;
	_curDivisor = 1;
}

bool Division::_quittingCheck()
{
	if (_curDivisor*_curDivisor >= _tarNum)
		return true;
	
	return false;
}
