#ifndef __P8_HEADER_H__
#define __P8_HEADER_H__

#include <iostream>
#include <vector>
#include <fstream>

class NumberSeries
{
private:
	std::vector<int> arr;
	std::vector<int>::const_iterator cWRevItPos;	// window�� ������ element ��ġ
	int windowSize;
	int curProduct;
	int maxProduct;	

	void readFile(const std::string& _fileName);
	bool objErrorTest();	// return false if it failed test  //rev
	bool outOfRangeWindowTest(std::vector<int>::const_iterator _startIt, int _offset)	// offset�� vector::end()�� �����ϸ� false return	//rev
	{
		return false;
	}		// return false if it failed test	//rev
	bool slide(int _steps);		//rev
public:
	NumberSeries();
	NumberSeries(const char * _fileName, int _sizeOfSeries, int _offset);
	~NumberSeries();
	// accessor
	std::vector<int>& get_arr();
	// mutator

	int getMaxProduct(int _numOfReading);	//rev
	
};


#endif