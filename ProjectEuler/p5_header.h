#pragma once

#ifndef __P5_HEADER_H__
#define __P5_HEADER_H__

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

// get all prime factors of _number
std::vector<std::pair<int, int>> factorization(int _number);

// get the smallest positive number that is 
//evenly divisible b all of the numbers from 1 to _number
int getNumber(int _number);



#endif