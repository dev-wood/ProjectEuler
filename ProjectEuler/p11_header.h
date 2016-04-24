#pragma once

#ifndef __P11_HEADER_H__
#define __P11_HEADER_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

class RowComponent;

class NumberGrid
{
private:

public:
	int _xLen, _yLen;
	std::vector<int> _arr;
public:
	NumberGrid();
	NumberGrid(int xLen, int yLen);
	NumberGrid(const std::string& fileName);
	void readFile(const std::string& fileName);
	RowComponent operator[](int row);	// NumberGird[row][col]
	
};
std::ostream& operator << (std::ostream& os, const NumberGrid& ng);

class RowComponent
{
private:
	std::vector<int>::iterator _it;
private:
	RowComponent();
	RowComponent(std::vector<int>::iterator it);
public:
	int& operator[](int col);
	
	friend NumberGrid;
};

class Element
{
public:
	Element * _next;
	int _val;
public:
	Element();
	Element(int val);
	Element(int val, Element*);
};

class FixedSizeQueue
{
public:
private:
	Element * _addr;	// address of array of Element
	Element * _back;	// position where the next new value would be put
	int _numOfZero;
	int _prod;
private:
	FixedSizeQueue();
	void _updateQue(int pushedVal, int poppedVal);
public:
	FixedSizeQueue(unsigned int windSz);
	~FixedSizeQueue();

	void push_back(int val);
	void clear();
	void print();

	// accessor
	int getProd();
};
typedef FixedSizeQueue FQueue;

class JointClass
{
	enum struct Direction : int
	{
		ROW,
		COL,
		FSLASH,
		BSLASH
	};
private:
	NumberGrid _ng;
	int _largestProd;
	unsigned int _windSz;
	FixedSizeQueue _que;
private:
	JointClass();

	bool _isPointValid(int row, int col);
	void _decideNextPosition(Direction dir, int & row, int & col);
	int _procOneLine(Direction dir, int row, int col);
	int _procRowDir();
	int _procColDir();
	int _procFSlashDir();
	int _procBSlashDir();
	bool _compareProd(int newVal);	// if largest product is updated, returns true. Otherwise false.
public:
	JointClass(const std::string& fileName, int windSz);
	void process();

	// accessor
	int get_largestProd();

};



#endif // !__P11_HEADER_H__