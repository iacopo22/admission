#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // If the user doesn't insert a file name the program returns an error
    if (argc != 2)
    {
        printf("The program accepts exactly one command line argument, i.e. the name of a forensic "
               "image.\n");
        return 1;
    }

    // The program open the file
    FILE *memory = fopen(argv[1], "r");

    // If the file is empty the program returns an error
    if (memory == NULL)
    {
        printf("Could not open the forensic image.\n");
        return 1;
    }

    // According to FAT file system each block is 512 bytes
    BYTE block[512];

    // Pointer to the memory batch for the JPEG title
    char filename[8];
    sprintf(filename, "%03i.jpg", 0);
    FILE *jpg = fopen(filename, "w");

    int counter = 0;

    while (fread(block, 1, 4, memory) == 4)
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            break;
        }
    }

    int pos = ftell(memory);
    rewind(memory);
    fseek(memory, pos - 4, SEEK_SET);

    while (fread(block, 1, 512, memory) == 512)
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                fwrite(block, 1, 512, jpg);

                counter++;
            }
            else
            {
                fclose(jpg);

                sprintf(filename, "%03i.jpg", counter);
                jpg = fopen(filename, "w");
                fwrite(block, 1, 512, jpg);

                counter++;
            }
        }
        else
        {
            fwrite(block, 1, 512, jpg);
        }
    }
    fclose(jpg);
    fclose(memory);
}
