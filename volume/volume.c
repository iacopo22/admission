// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef uint16_t BYTE_2;


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE header[HEADER_SIZE];
    BYTE b;

    fread(header, sizeof(b), HEADER_SIZE, input);
    fwrite(header, sizeof(b), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    BYTE_2 samples;

    fseek(input, 0, SEEK_END);
    int end = ftell(input);

    fseek(input, 44, SEEK_SET);
    int start = ftell(input);

    for (int i = 0; i < ((end - 44)/2); i++)
    {
        fread(&samples, sizeof(samples), 1, input);
        samples *= factor;
        fwrite(&samples, sizeof(samples), 1, output);
    }

    printf("%ld\n", ftell(output));

    // Close files
    fclose(input);
    fclose(output);
}
