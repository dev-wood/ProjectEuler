#include "p8_header.h"

int main()
{
	NumberSeries ns(1000);

	ns.readFile("p8.txt");

	


	return 0;
}



//// test
//int main()
//{
//	NumberSeries ns(1000);
//
//	ns.readFile("p8.txt");
//	std::vector<int> vec = ns.get_arr();
//
//	for (auto it = vec.cbegin(); it != vec.cend(); it++)
//		std::cout << *it;
//	std::cout << std::endl;
//
//	return 0;
//}