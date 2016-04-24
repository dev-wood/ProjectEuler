#include "p12_header.h"

int main()
{
	int idx = 1;

	TriangleNumber tn;

	while (1)
	{
		if (Division::getNumOfDevisor(tn[idx]) > 500)
			break;

		idx++;
	}

	std::cout << "Answer is: " << tn[idx] << std::endl;

	return 0;
}
// Answer is 76576500.

//// test3
//int main()
//{
//	std::cout << Division::getNumOfDevisor(10) << std::endl;
//
//	return 0;
//}

//// test2
//int main()
//{
//	TriangleNumber tr(10);
//
//	tr.print();
//
//	return 0;
//}

//// test1
//int main()
//{
//	double d = std::sqrt(100);
//	int a = std::sqrt(10);
//
//	std::cout << d << " " << a << std::endl;
//
//	return 0;
//}