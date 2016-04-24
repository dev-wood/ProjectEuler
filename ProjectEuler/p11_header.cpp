#include "p11_header.h"

NumberGrid::NumberGrid() : _xLen(0), _yLen(0)
{
}

NumberGrid::NumberGrid(int xLen, int yLen) : _xLen(xLen), _yLen(yLen)
{
}

NumberGrid::NumberGrid(const std::string & fileName)
{
	readFile(fileName);
}

void NumberGrid::readFile(const std::string & fileName)
{
	std::ifstream strm;
	strm.open(fileName);

	// read file
	cout << "Read file.." << endl;
	char ch;
	std::stringstream ss;
	while (strm.get(ch))
	{
		if (ch == ' ') {
			ss << ch;
			_xLen++;
		}
		else if (ch == '\n') {
			ss << ' ';
			_xLen++; _yLen++;
		}
		else {
			ss << ch;
			if (strm.peek() == EOF) {
				_xLen++; _yLen++;
			}
		}
	}
	_xLen /= _yLen;
	_arr.reserve(_xLen * _yLen);

	// make vector array _arr
	cout << "Making vector array.." << endl;
	int num;
	while (ss >> num) {
		_arr.push_back(num);
	}

	strm.close();

	return;

	/*
	cout << "Read file: " << fileName << endl;

	std::ifstream strm;
	strm.open(fileName);

	// read from file, push data into ss
	cout << "Data read from file and write into stream." << endl;
	char ch;
	std::stringstream ss;
	while (strm.get(ch))
	{
		if (ch == ' ') {
			_xLen++;
			ss << ch;
		} else if (ch == '\n') {
			_xLen++; _yLen++;
			ss << ' ';
		} else
			ss << ch;
	}
	_yLen++; _xLen++;
	_xLen /= _yLen;
	_arr.reserve(_yLen);
	for (int i = 0; i < _yLen; i++)
		_arr.push_back(std::vector<int>(_xLen));

	// data extract from ss into 2-dim array
	cout << "Data write in NumberGrid object." << endl;
	int n = 0;
	auto rit = _arr.begin();
	auto cit = rit->begin();
	while (ss >> n)
	{
		*cit = n;
		cit++;

		if (cit == rit->end()) {
			rit++;
			if (rit != _arr.end())
				cit = rit->begin();
		}
	}

	strm.close();

	return;
	*/
}

RowComponent NumberGrid::operator[](int row)
{
	if (row >= _yLen) {
		cout << "Array out of bound." << endl;
		exit(1);
	}
	return RowComponent(_arr.begin() + _xLen*row);
}

//RowComponent::RowComponent() : _row(0), _val(0)
//{
//}
//
//RowComponent::RowComponent(int row) : _row(row)
//{
//}

RowComponent::RowComponent() : _it(std::vector<int>::iterator())
{}

RowComponent::RowComponent(std::vector<int>::iterator it) :_it(it)
{}

int& RowComponent::operator[](int col)
{
	return *(_it + col);
}

std::ostream & operator<<(std::ostream & os, const NumberGrid & ng)
{
	cout << "x lenght: " << ng._xLen << " / y length: " << ng._yLen << endl;
	//cout << std::cout.width(2);
	for (int r = 0; r < ng._yLen; r++) {
		cout << "|";
		for (int c = 0; c < ng._xLen; c++)
			cout << std::setw(3) << ng._arr[r*ng._xLen + c] << " ";
		cout << "|" << endl;
	}
	return os;
}

Element::Element() : _val(0), _next(nullptr)
{}
Element::Element(int val) : _val(val)
{}
Element::Element(int val, Element * pt) : _val(val), _next(pt)
{}

FixedSizeQueue::FixedSizeQueue() : _numOfZero(0), _prod(0), _back(nullptr)
{}

void FixedSizeQueue::_updateQue(int pushed, int popped)
{
	if (pushed == 0) {	// push val is zero
		if (popped == 0)	// the number pop from queue is zero
			;	// do nothing
		else				// the number pop from queue is not zero
			_numOfZero++;
		_prod = 0;
	}
	else {				// push val is not zero
		if (popped == 0)	// the number pop from queue is zero
		{
			if (_numOfZero == 1)	// the only zero value in the queue has been popped
			{	// get product
				Element * tmp = _addr;
				_prod = 1;
			
				do {
					_prod *= tmp->_val;
					tmp = tmp->_next;
				} while (tmp != _addr);
			}						// there are several zero values in the queue
			else
			{
				// do nothing
			}
			_numOfZero--;
		}
		else				// the number pop from queue is not zero
		{
			if (_numOfZero == 0) {
				_prod /= popped;
				_prod *= pushed;
			}
			else
				;	// do nothing
		}
	}
}

FixedSizeQueue::FixedSizeQueue(unsigned int windSz) : _numOfZero(windSz), _prod(0)
{
	_addr = new Element[windSz];
	_back = _addr;

	for (int i = 0; i < windSz - 1; ++i)
		_addr[i]._next = &_addr[i + 1];
	_addr[windSz - 1]._next = _addr;
}

FixedSizeQueue::~FixedSizeQueue()
{
	delete[] _addr;
}

void FixedSizeQueue::push_back(int val)
{
	// new value added to queue
	int popped = _back->_val;
	_back->_val = val;
	_back = _back->_next;

	// queue state (_numOfZero, _prod) update
	_updateQue(val, popped);
}

int FixedSizeQueue::getProd()
{
	return _prod;
}

void FixedSizeQueue::clear()
{
	Element * tmp = _addr;
	
	do {
		push_back(0);
		tmp = tmp->_next;
	} while (tmp != _addr);

}

void FixedSizeQueue::print()
{
	Element * tmp = _addr;
	std::cout << " (Queue values: ";
	do {
		std::cout << tmp->_val << ", ";
		tmp = tmp->_next;
	} while (tmp != _addr);
	std::cout << ")" << std::endl;
}

bool JointClass::_isPointValid(int row, int col)
{
	if (row < _ng._yLen && col < _ng._xLen && row >= 0 && col >= 0)
		return true;
	else
		return false;
}
void JointClass::_decideNextPosition(Direction dir, int & row, int & col)
{
	if (dir == Direction::ROW) 
		col++;
	else if (dir == Direction::COL)
		row++;
	else if (dir == Direction::FSLASH)	// '/'
	{
		row--;
		col++;
	}
	else {		// '`.'
		row++;
		col++;
	}
}
int JointClass::_procOneLine(Direction dir, int startRow, int startCol)
{
	_que.clear();

	int r = startRow;
	int c = startCol;
	int tmpProd = 0;

	while (_isPointValid(r, c))
	{
		_que.push_back(_ng[r][c]);

		if (tmpProd < _que.getProd())
			tmpProd = _que.getProd();

		_decideNextPosition(dir, r, c);
	}

	std::cout << "_procOneLine() completed. return value: " << tmpProd << std::endl;

	return tmpProd;
}
int JointClass::_procRowDir()
{
	Direction dir = Direction::ROW;
	int row(0), col(0);
	FixedSizeQueue tmpQue(_windSz);

	for (row = 0; row < _ng._yLen; row++) {
		int tmpProd = _procOneLine(dir, row, col);
		_compareProd(tmpProd);
	}
	
	return 0;
}
int JointClass::_procColDir()
{
	Direction dir = Direction::COL;
	int row(0), col(0);

	for (col = 0; col < _ng._xLen; col++) {
		int tmpProd = _procOneLine(dir, row, col);
		_compareProd(tmpProd);
	}

	return 0;
}
int JointClass::_procFSlashDir()
{
	Direction dir = Direction::FSLASH;
	int row, col;

	for (row = _ng._yLen - 1, col = 0; row > _windSz; --row) {
		int tmpProd = _procOneLine(dir, row, col);
		_compareProd(tmpProd);
	}
	for (row = _ng._yLen - 1, col = 1; col < _windSz; ++col) {
		int tmpProd = _procOneLine(dir, row, col);
		_compareProd(tmpProd);
	}

	return 0;
}
int JointClass::_procBSlashDir()
{
	Direction dir = Direction::BSLASH;
	int row, col;

	for (row = 0, col = 0; row < _windSz; ++row) {
		int tmpProd = _procOneLine(dir, row, col);
		_compareProd(tmpProd);
	}
	for (row = 0, col = 1; col < _windSz; ++col) {
		int tmpProd = _procOneLine(dir, row, col);
		_compareProd(tmpProd);
	}
	return 0;
}

bool JointClass::_compareProd(int newVal)
{
	if (newVal > _largestProd) {
		std::cout << "Largest value updated. Old value: " << get_largestProd() << ", new value: " << newVal << std::endl;
		_largestProd = newVal;
		return true;
	}
	return false;
}

JointClass::JointClass(const std::string & fileName, int windSz) : _ng(fileName), _windSz(windSz), _que(windSz), _largestProd(0)
{}

void JointClass::process()
{
	_procRowDir();
	_procColDir();
	_procFSlashDir();
	_procBSlashDir();
}

int JointClass::get_largestProd()
{
	return _largestProd;
}
