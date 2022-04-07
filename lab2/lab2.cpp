#include <stdio.h>

int main()
{
	signed char mask = 0xEE;
	char i;
	signed char array[9] = { -50, 5, 85, -102, -17, 42, -126, -21, 103 };
		
	for (i = 0; i < 9; ++i)
	{
		if (array[i] < 0)
		{
			array[i] = array[i] >> 4;
		}
		else
		{
			array[i] &= mask;

		}
	}

	for (i = 0; i < 9; ++i)
	{
		printf("%d", array[i]);
		printf(" ");
	}
		
	return 0;
}
