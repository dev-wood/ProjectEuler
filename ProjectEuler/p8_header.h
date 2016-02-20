#ifndef __P8_HEADER_H__
#define __P8_HEADER_H__

#include <iostream>
#include <vector>
#include <fstream>

class NumberSeries
{
private:
	std::vector<int> arr;
	std::vector<int>::const_iterator inWndLastIt;		//rev
	int maxProduct;		//rev
	int curProduct;		//rev
	int wnSize;

	bool slide(int _offset);		//rev
public:
	NumberSeries();
	NumberSeries(const std::string& _fileName, int _szSeries, int _szWnd);
	~NumberSeries();
	// accessor
	std::vector<int>& get_arr();
	// mutator

	void readFile(const std::string& _fileName, int _szSeries);
	int getMaxProduct();	//rev
	
};


#endif