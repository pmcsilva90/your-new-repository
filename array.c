#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size = 0;
    int array[size];

    scanf("%i", &size);

    for(int i = 1; i <= size; i = i * 2)
    {
        printf("%i\n", array[i]);
    }
}
