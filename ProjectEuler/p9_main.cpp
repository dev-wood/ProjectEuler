#include <iostream>
#include "p9_header.cpp"

int main()
{
	std::cout << "Program starts." << std::endl;

	int a, b, c;
	bool ansFound = false;

	int sumOfBC;
	for (a = 1; a < 1000; a++)
	{
		sumOfBC = 1000 - a;
		b = a + 1;
		c = sumOfBC - b;
		while (b < c) {
			if ((a*a + b*b) == c*c) {
				ansFound = true;
				break;
			}			
			//std::cout << "(" << a << ", " << b << ", " << c << ")" << std::endl;

			b++; c--;	
		}

		if (ansFound)
			break;
	}

	if (ansFound == true)
		std::cout << "Answer is : " << a << " " << b << " " << c << std::endl;
	else
		std::cout << "Couldn't find answer." << std::endl;

	std::cout << "Program ends." << std::endl;

	return 0;
}
// Answer : 200, 375, 425