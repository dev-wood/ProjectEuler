#include "p8_header.h"

int main()
{
	NumberSeries ns("p8.txt", 1000, 8);

	int maxProduct = ns.getMaxProduct();

	std::cout << "Max product value : " << maxProduct << std::endl;


	return 0;
}

// answer : 7838208