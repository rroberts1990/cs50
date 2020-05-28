#include <cs50.h>
#include <stdio.h>

void pyramid(int x);

int main(void)
{
    int size;
    do
    {
        size = get_int("How big should the pyramid be?\n");
    }
    while (size <= 0 || size > 8);
    pyramid(size);
}

void pyramid(int x)
{
    int i;
    int j;
    int k;
    int l;
    //outer for loop to handle height
    for (i = 1; i <= x; i++)
    {
        //first inner for loop to handle leading spaces
        for (k = x - 1; k >= i; k--)
        {
            printf("%c", ' ');
        }
        //second inner for loop to handle left pyramid
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        //third inner for loop to handle right pyramid
        for (l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
