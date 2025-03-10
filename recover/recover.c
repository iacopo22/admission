#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("The program accepts exactly one command line argument, i.e. the name of a forensic image.\n");
        return 1;
    }

    FILE *memory = fopen(argv[1], "r");
    if (memory == NULL)
    {
        printf("Could not open the forensic image.\n");
        return 1;
    }

    BYTE block[512];

    char filename[8];
    sprintf(filename, "%03i.jpg", 0);
    FILE *jpg = fopen(filename, "w");

    int counter = 0;

    for (int i = 0; i < ceil(end / 512); i++)
    {
        fread(block, 1, 4, memory);

        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            break;
        }
    }
    printf("%x\n", block[0]);
    printf("%x\n", block[1]);
    printf("%x\n", block[2]);
    printf("%x\n", block[3]);

    int pos = ftell(memory);
    printf("%i\n", pos);
    rewind(memory);
    fseek(memory, pos - 3, SEEK_SET);
    int pos1 = ftell(memory);
    printf("%i\n", pos1);



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

}
