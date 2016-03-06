#include "p10_header.h"

int main()
{
	//Prime prime(100000);

	//prime.print();
	//Prime prime;

	//std::cout << prime[10000] << std::endl;

	Prime prime(2000000);

	int sum = 0;
	for (auto it : prime)
		sum += it;
	std::cout << "sum: " << sum << std::endl;

	return 0;
}
// answer : 1179908154






//// test
//int main()
//{
//	Prime p1;
//	std::cout << "p1[0]: " << p1[0] << std::endl;
//	std::cout << "p1[3]: " << p1[3] << std::endl;
//	p1.print();
//	std::cout << "------------" << std::endl;
//
//	Prime p2(14);
//	p2.print();
//
//	return 0;
//}