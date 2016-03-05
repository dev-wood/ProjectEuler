#pragma once

#ifndef __P10_HEADER__
#define __P10_HEADER__

#include <iostream>
#include <vector>

class Prime
{
private:
	std::vector<int> arr;
	bool primeCheck(int _nextCandidate);	// Prime::arr 를 구하는데 사용되는 함수.
											//	prime 후보가 지금까지 찾은 소수들로 소인수분해가 되는지 확인.
	int getNextPrimeInArr();
	void setPrimeArrTo(int _n);			// Prime::arr를 구하는 함수. arr[n]까지 prime을 구함.
	void setPrimeArrLessThan(int _val);	// Prime::arr를 구하는 함수. _val 보다 작은 prime을 모두 구함.
public:
	Prime();
	Prime(int _lessThan);
	int operator[](int _n);
	void print();

	//auto begin();
	//auto end();
	//std::vector<int>::iterator begin();
	//std::vector<int>::iterator end();
	std::vector<int>::const_iterator begin();
	std::vector<int>::const_iterator end();
};



#endif 