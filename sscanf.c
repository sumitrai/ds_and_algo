#include <stdio.h>

int main(void)
{
    int a, b;
    int c, d;

    a = b = c = d = 0;

    scanf("%d %d", &a, &b);
    printf("HI-1: %d %d %d %d\n", a, b, c, d);
    fflush(stdin);
    scanf("%d %d", &c, &d);
    printf("HI-2: %d %d %d %d\n", a, b, c, d);
}
