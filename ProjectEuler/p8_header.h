#pragma once

#ifndef __P8_HEADER_H__
#define __P8_HEADER_H__

#include <iostream>
#include <vector>
#include <fstream>

class NumberSeries
{
private:
	std::vector<int> arr;

	int getProduct(std::vector<int>::const_iterator& cit, int numOfReading);
public:
	NumberSeries();
	NumberSeries(int _sizeOfSeries);
	~NumberSeries();
	
	// accessor
	std::vector<int>& get_arr();
	// mutator
	
	void readFile(const std::string& _fileName);
	
};


#endif