#pragma once

#ifndef __P10_HEADER__
#define __P10_HEADER__

#include <iostream>
#include <vector>

#define VEC_RESERVED_SPACE 200000
#define CHECK_NUMBER 10000

class Prime
{
private:
	std::vector<int> arr;
	bool primeCheck(int _nextCandidate);	// Prime::arr �� ���ϴµ� ���Ǵ� �Լ�.
											//	prime �ĺ��� ���ݱ��� ã�� �Ҽ���� ���μ����ذ� �Ǵ��� Ȯ��.
	int getNextPrimeInArr();
	void setPrimeArrTo(int _n);			// Prime::arr�� ���ϴ� �Լ�. arr[n]���� prime�� ����.
	void setPrimeArrLessThan(int _val);	// Prime::arr�� ���ϴ� �Լ�. _val ���� ���� prime�� ��� ����.
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