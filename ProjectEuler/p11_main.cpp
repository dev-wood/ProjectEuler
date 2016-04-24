#include "p11_header.h"

#include <iostream>
#include <vector>

// test4
int main()
{
	JointClass jc("p11.txt", 4);
	jc.process();

	std::cout << "Largest product is: " << jc.get_largestProd() << std::endl;
	
	return 0;
}
// answer: 70600674

//// test3
//int main()
//{
//	FixedSizeQueue win(4);
//
//	for (int i = 1; i < 10; ++i) {
//		std::cout << "----------------" << std::endl;
//		win.push_back(i);
//		win.print();
//		std::cout << win.getProd() << std::endl;
//	}
//
//	win.push_back(0);
//	win.print();
//	std::cout << win.getProd() << std::endl;
//	win.push_back(0);
//	win.print();
//	std::cout << win.getProd() << std::endl;
//	win.push_back(1);
//	win.print();
//	std::cout << win.getProd() << std::endl;
//	win.push_back(2);
//	win.print();
//	std::cout << win.getProd() << std::endl;
//	win.push_back(3);
//	win.print();
//	std::cout << win.getProd() << std::endl;
//	win.push_back(4);
//	win.print();
//	std::cout << win.getProd() << std::endl;
//
//	std::cout << std::endl;
//	win.print();
//	win.clear();
//	win.print();
//
//	return 0;
//}

//// test2
//int main()
//{
//	NumberGrid ng;
//	ng.readFile("p11_test.txt");
//
//	cout << ng;
//
//	for (int i = 0; i < ng._xLen; i++)
//		cout << ng._arr[i] << endl;
//
//	ng[0][0] = 999;
//
//	cout << ng;
//
//	return 0;
//}

//// test1
//int main()
//{
//	std::vector< std::vector<int> > darr;
//
//	std::vector<int> tmp1({ 1,2 });
//	std::vector<int> tmp2({ 3,4 });
//	darr.push_back(tmp1);
//
//	darr.push_back(std::vector<int>{3, 4});	
//	
//	cout << darr[0][0] << darr[0][1] << endl;
//	cout << darr[1][0] << darr[1][1] << endl;
//
//
//	return 0;
//}
