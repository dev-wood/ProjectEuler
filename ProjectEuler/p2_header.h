int getFiboSum1(int lessThan)
{
	int fiboSum = 0;
	int bbFibo = 1;
	int bFibo = 0;
	int fibo = 0;

	int n = 0;

	while (fibo < lessThan) {

		fibo = bbFibo + bFibo;
		bbFibo = bFibo;
		bFibo = fibo;

		n++;

		if (n % 2 == 0)
			fiboSum += fibo;
	}
	return fiboSum;
}

int getFibosum2(int lessThan)
{
	int fiboSum = 0;
	int fibo = 0;
	int bfibo = 1;

	int n = 0;

	while (fibo < lessThan) {
		int temp = bfibo;
		bfibo = fibo;
		fibo = temp;

		fibo += bfibo;
		n++;

		if (n % 2 == 0) {
			fiboSum += fibo;
		}
	}

	return fiboSum;
}
