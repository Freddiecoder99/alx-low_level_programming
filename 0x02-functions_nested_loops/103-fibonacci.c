#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int num1 = 1, num2 = 2, next, sum = 2;

	while (num2 <= 4000000)
	{
		next = num1 + num2;

		if (next % 2 == 0)
			sum += next;

		num1 = num2;
		num2 = next;
	}

	printf("%d\n", sum);

	return 0;
}

