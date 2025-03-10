#include <stdio.h>
#include <stdlib.h>

typedef int8_t BYTE;

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
    int end = ftell(memory) / 512;
    printf("%i\n", end);

    BYTE block[];

    for (int i = 0; i < end; i++)
    {
        fread(block[], BYTE, 512, memory);
    }

}
