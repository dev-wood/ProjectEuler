#include <iostream>

int main()
{
	int sum = 0;
	int n = 1;

	auto div_3 = [&] {
		if (n % 3 == 0) {
			std::cout << n << std::endl;
			return true;
		}
		else
			return false;
	};
	auto div_5 = [&] {
		if (n % 5 == 0) {
			std::cout << n << std::endl;
			return true;
		}
		else
			return false;
	};
	
	while (n < 1000) {
		if (div_3() || div_5())		
			sum += n;
		n++;
	}

	std::cout << "sum: " << sum << std::endl;

	return 0;
}

// the order of div_3() and div_5() is important.
// If the first one is true, the letter one won't be called by Short circuit rule.
