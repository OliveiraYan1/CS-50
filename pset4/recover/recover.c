#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // CHECK USAGE
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // OPEN MEMORY CARD
    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        return 1;
    }

    // Variable to store the bytes
    unsigned char buffer[512];

    // Counter for numebr of images generated
    int count_jpeg = 0;

    // File pointer to handled the JPEGs that will be recovered
    FILE *output = NULL;

    // Allocate memory for filename[8]
    char *filename = malloc(8 * sizeof(char));

    // Read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input))
    {
        // Check if bytes indicate start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Write the JPEG filenames
            sprintf(filename, "%03i.jpg", count_jpeg);

            // Open output file for writing
            output = fopen(filename, "w");

            // Count number of images
            count_jpeg++;
        }
        // Check if the output file has not been used for valid input
        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }
    free(filename);
    fclose(output);
    fclose(input);
    return 0;
}
