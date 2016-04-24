#pragma once

#include <cmath>
#include <deque>
#include <vector>
#include <iostream>

namespace my {
	typedef unsigned int uint;
}

class TriangleNumber
{
public:
	TriangleNumber();
	TriangleNumber(my::uint nth);
	my::uint operator[] (my::uint idx);

	my::uint getNextNumber();
	void print();

	// accessor
	my::uint get_lastAddedNum();	// return last added 
public:

private:
	my::uint _lastAddedNum;		// last added number in sum of numbers to get triangle number
private:
	std::deque<my::uint> _arr;	// produced triangle number stored in this array
};

/*********************************************************************
* Division class
*	calculator class to counting the number of devisor.(having no object)
**********************************************************************/
class Division
{
public:
	static my::uint getNumOfDevisor(my::uint num);	// get the number of divisor of num
public:
private:
	Division();
	
	static void _init();	// initiating static values
	static bool _quittingCheck();	// quitting condition check function : quit if it return true.
private:
	static my::uint _tarNum;		// target number to get the number of divisions
	static my::uint _numOfDiv;		// the number of divisor
	static my::uint _curDivisor;	// current divisor indicator

};
//my::uint Division::_tarNum = 0;		//rev
//my::uint Division::_numOfDiv = 0;
//my::uint Division::_curDivisor = 0;