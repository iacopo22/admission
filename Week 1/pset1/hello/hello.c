#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Function used to ask and obtain the name
    string name = get_string("What's your name?\n");
    //Function used to greet andvprint the answer
    printf("hello, %s\n", name);
}