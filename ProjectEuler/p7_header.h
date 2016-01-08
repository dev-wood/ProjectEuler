#pragma once

#ifndef __P7_HEADER_H__
#define __P7_HEADER_H__

#include <iostream>
#include <vector>

class Prime
{
private:
	
	static std::vector<int> arr;
	static bool primeCheck(int _num);
public:
	Prime();
	static int getNthNumber(int _nth);
	static void print();
};



#endif
