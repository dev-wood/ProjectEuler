#ifndef __P8_HEADER_H__
#define __P8_HEADER_H__

#include <iostream>
#include <vector>
#include <fstream>

class NumberSeries
{
private:
	std::vector<int> arr;

	std::vector<int>::const_iterator cWndRevIt;	// window�� ���Ե� elem �� last element ��ġ
	int windowSize;
	int curProduct;
	int maxProduct;	

	void readFile(const std::string& _fileName);
	bool slide(int _steps);		// window�� _steps ��ŭ �����̵� ��Ŵ. ���� �� true, �����̵� �� end() ������ false ��ȯ.
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