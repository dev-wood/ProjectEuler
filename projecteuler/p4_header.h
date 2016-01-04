
#ifndef __P4_HEADER_H__
#define __P4_HEADER_H__

#include <iostream>
#include <cmath>
#include <vector>

// check _num if it consists of two factor
//both of which are _digits digits.
bool checkNumber(int _num, int _digits);			

// check _factor1 if it is the factor of _origNum and return it's pair factor
// if _factor1 is not the factor of _origNum, then return 0;
int getPairFactor(int _orig, int _factor1);	

// check if the target number is _digits number.
bool checkDigits(int _tarNum, int _digits);		

#endif