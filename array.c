#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int lenght;
    do
    {
        lenght = get_int("Length: ");
    }
    while (lenght < 1);

    int i;
    int array[lenght];


    for(i = 1; i <= lenght; i++)
    {
        array[i] = array[i - 1] * 2;
        printf("%i\n", array[i]);
    }

}
