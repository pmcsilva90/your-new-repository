#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
// Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];
    int countImage = 0;
    FILE *outputFile = NULL;
    char *filename = malloc(8 * sizeof(char))

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        if ((buffer[3] & 0xf0) == 0xe0)
        // Create JPEGs from the data    // Open output file
        FILE *img = fopen("img.jpeg", "w");
        if (img == NULL)
        {
            fclose(img);
            printf("Could not create %s.\n", img);
            return 1;
        }
    }
}
