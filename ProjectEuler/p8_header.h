#ifndef __P8_HEADER_H__
#define __P8_HEADER_H__

#include <iostream>
#include <vector>
#include <fstream>

class NumberSeries
{
private:
	std::vector<int> arr;
	std::vector<int>::const_iterator curIt;		//rev
	int maxProduct;		//rev
	int curProduct;		//rev
	int windowSize;

	bool slide(int _offset);		//rev
public:
	NumberSeries();
	NumberSeries(int _sizeOfSeries);
	~NumberSeries();
	// accessor
	std::vector<int>& get_arr();
	// mutator

	void readFile(const std::string& _fileName);
	int getMaxProduct(int _numOfReading);	//rev
	
};


#endif