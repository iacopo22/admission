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

    fseek(memory, 0, SEEK_END);
    int end = ftell(memory);
    printf("%i\n", end);

    BYTE block[512];

    for (int i = 0; i < ceil(end / 512); i++)
    {
        fread(&block, sizeof(block), 512, memory);

        int counter = 0;

        sprintf("jpg", "%03i.jpg", 1);
        FILE *jpg = fopen("jpg", "w");

        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                fwrite(block, sizeof(block), 512, jpg);

                counter++;
            }
            else
            {
                fclose(jpg);

                sprintf("jpg", "%03i.jpg", counter + 1);
                FILE *jpg1 = fopen("jpg", "w");
                fwrite(block, sizeof(block), 512, jpg1);
            }
        }
        else
        {
            if (counter == 0)
            {
                fwrite(block, sizeof(block), 512, jpg);
            }
            else
            {
                fwrite(block, sizeof(block), 512, jpg1);
            }
        }
    }

}
