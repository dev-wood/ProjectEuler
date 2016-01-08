
int getSumOfSquare(int _untilNum)
{
	int i = 0;
	int sum = 0;

	while (i++ < _untilNum)
	{
		sum += i*i;
	}

	return sum;
}

int getSquareOfSum(int _untilNum)
{
	int i = 0;
	int sum = 0;

	while (i++ < _untilNum)
	{
		sum += i;
	}

	return sum*sum;
}
int getSolution(int _num)
{
	return getSquareOfSum(_num) - getSumOfSquare(_num);
}