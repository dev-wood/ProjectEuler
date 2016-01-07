#include "p5_header.h"

//int main()
//{
//
//	return 0;
//}





// test
int main()
{
	std::vector<std::pair<int, int>> testVec;

	testVec = factorization(20);
	//testVec=std::move(factorization(16));

	//// test1
	//for (auto it = testVec.cbegin(); it != testVec.cend(); it++)
	//	std::cout << "(" << it->first << ", " << it->second << ")" << " ";
	//std::cout << std::endl;

	// test2
	std::cout << getNumber(2) << std::endl;

	std::cout << "End of program." << std::endl;

	return 0;
}