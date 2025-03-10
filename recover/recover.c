#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef __int8_t BYTE;

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

    for (int i = 0; i < (end / 512); i++)
    {
        fread(&block, sizeof(block), 512, memory);

        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {

        }
    }

}
