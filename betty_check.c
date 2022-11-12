#include <stdio.h>
#include <stdlib.h>

/**
 * void - contains set of integers
 *
 * @scanf - allows intake of integers
 *
 * Return: 0
 */

int main(void)
{
	int a, b, c;

	a = b = c = 0;

	printf("Enter 3 Numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("Result: %d\n", a + b + c);

	return (0);
}
