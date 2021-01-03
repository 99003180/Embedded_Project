#include "sum_of_digits.h"


int summation (int b)
{
	int y = 0;
	while (b > 0)
	{
		int r = b % 10;
		b = b / 10;
		y = y + r;
	}
	return y ;
}