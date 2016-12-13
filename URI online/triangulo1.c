#include <stdio.h>

int main(void)
{
    int x,y,z,w;

    scanf("%d %d %d %d", &x, &y, &z, &w);

    if ((x < z+w) && (z < x+w) && (w < x+z))
    {
        printf("S\n");
        return 0;
    }
    else if ((x < y+w) && (y < x+w) && (w < x+y))
    {
        printf("S\n");
        return 0;
    }
    else if ((x < y+z) && (y < x+z) && (z < x+y))
    {
        printf("S\n");
        return 0;
    }
    else if ((y < w+z) && (w < y+z) && (z < w+y))
    {
        printf("S\n");
        return 0;
    }
    else
        printf("N\n");

    return 0;
}