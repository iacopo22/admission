#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
#define block_size 512
#define length_name_file 8

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
    BYTE block[block_size];

    // Pointer to the memory batch for the JPEG title
    char filename[length_name_file];
    // The string 000.jpg is stored in the filename batch of memory
    sprintf(filename, "%03i.jpg", 0);
    // Pointer to store the JPEG file (the JPEG file is store in the DISK not in the memory)
    FILE *jpg = fopen(filename, "w");

    int counter = 0;

    // Now the program can read each block
    while (fread(block, 1, block_size, memory) == block_size)
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            // If it's the first JPEG file
            if (counter == 0)
            {
                fwrite(block, 1, block_size, jpg);

                counter++;
            }
            // Otherwise I close the previous one and I create a new one always referred to the
            // same space in memory. (Memory != Disk). Memory is overscripted and I create a new
            // file in the disk.
            else
            {
                fclose(jpg);

                sprintf(filename, "%03i.jpg", counter);
                jpg = fopen(filename, "w");
                fwrite(block, 1, block_size, jpg);

                counter++;
            }
        }
        // If the image is bigger than one block of 512 bytes
        else
        {
            if (counter != 0)
            {
                fwrite(block, 1, block_size, jpg);
            }
        }
    }
    fclose(jpg);
    fclose(memory);
}
