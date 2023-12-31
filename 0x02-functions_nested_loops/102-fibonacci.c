#include <stdio.h>

/**
 * Calculates and prints the Fibonacci sequence up to the 50th term.
 */
int main(void)
{
    int count, num1 = 1, num2 = 2, next;

    printf("%d, %d", num1, num2);

    for (count = 3; count <= 50; count++) {
        next = num1 + num2;
        printf(", %d", next);
        num1 = num2;
        num2 = next;
    }

    printf("\n");

    return 0;
}

