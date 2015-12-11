#include <iostream>

int main()
{
	int sum = 0;
	int n = 1;

	auto div_3 = [n] {
		if (n % 3 == 0)
			return true;
		else
			return false;
	};
	auto div_5 = [n] {
		if (n % 5 == 0)
			return true;
		else
			return false;
	};
	
	while (n < 1000) {
		if (div_3() && div_5())
			sum += n;
		n++;
	}

	std::cout << "sum: " << sum << std::endl;

	return 0;
}