#ifndef __P8_HEADER_H__
#define __P8_HEADER_H__

#include <iostream>
#include <vector>
#include <fstream>

class NumberSeries
{
private:
	std::vector<int> arr;

	std::vector<int>::const_iterator cWndRevIt;	// window에 포함된 elem 중 last element 위치
	int windowSize;
	int curProduct;
	int maxProduct;	

	void readFile(const std::string& _fileName);
	bool slide(int _steps);		// window를 _steps 만큼 슬라이드 시킴. 성공 시 true, 슬라이드 중 end() 만나면 false 반환.
public:
	NumberSeries();
	NumberSeries(const char * _fileName, int _sizeOfSeries, int _offset);
	~NumberSeries();
	// accessor
	std::vector<int>& get_arr();
	// mutator

	int getMaxProduct();
	
};


#endif