#include "p3_header.h"

int main()
{
	int testvalue;
	std::cout << "program start" << std::endl;
	std::cout << "Put number to find largest prime factor: ";
	std::cin >> testvalue;
	
	std::cout << findLargestPrimeFactor(testvalue) << std::endl;


	return 0;
}