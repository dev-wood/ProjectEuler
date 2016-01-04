#include "p4_header.h"

int main(void)
{
	int first = 9;
	int second = 9;
	int third = 9;
	int digits = 6;
	int num;

	while (1)
	{
		// generate palindrome
		if (digits == 6)	// which is 6 digits
		{
			num = first * (std::pow(10, digits - 1) + 1)
				+ second * (std::pow(10, digits - 2) + std::pow(10,1))
				+ third * (std::pow(10, digits - 3) + std::pow(10,2));
		}
		else if (digits == 5) {	// which is 5 digits
			num = first * (std::pow(10, digits - 1) + 1)
				+ second* (std::pow(10, digits - 2) + std::pow(10,1))
				+ third * std::pow(10, 2);
		}
		else {
			break;
		}
		std::cout << "Checking : " << num << std::endl;

		if (checkNumber(num, 3)) {
			break;
		}

		// update each digit of palindrome
		if (third == 0)
		{
			third = 9;
			
			if (second == 0)
			{
				second = 9;

				if (first == 1)
				{
					first = 9;
					digits--;
					if (digits < 5)
						break;
				}
				else {
					first--;
				}
			}
			else {
				second--;
			}
		}
		else {
			third--;
		}
	}
	
	if (digits == 4)
		std::cout << "There is no palinedrome which is product of two 3-digits number" << std::endl;
	else
		std::cout << "The number is " << num << "." << std::endl;

	return 0;
}
// Solved. The answer is 906609


////
//// test code
//int main()
//{
//	//// case1
//	//std::cout << checkDigits(989, 3) << std::endl;
//	//std::cout << checkDigits(99, 3) << std::endl;
//	//std::cout << checkDigits(111, 0) << std::endl;
//
//	//// case2
//	//std::cout << getPairFactor(100, 20) << std::endl;
//	//std::cout << getPairFactor(100, 3) << std::endl;
//
//	// case3
//	std::cout << checkNumber(100, 2) << std::endl;
//	std::cout << checkNumber(100, 3) << std::endl;
//	std::cout << checkNumber(10000, 3) << std::endl;
//
//	std::cout << "Program terminated." << std::endl;
//}