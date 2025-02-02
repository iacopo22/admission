#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string s);
int sentences(string s);
int words(string s);

int main(void)
{
    // Prompt the user for the text
    string text = get_string("Text: ");

    // Recall the functions and store the return values in the variables
    int number_letters = letters(text);
    int number_words = words(text);
    int number_sentences = sentences(text);

    // Calculate the variables used in the formula
    // Variables casted as float to store the decimal
    float L = ((float) number_letters / number_words) * 100;
    float S = ((float) number_sentences / number_words) * 100;

    int index;

    // Index of the grade
    index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade based on the index
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int letters(string s)
{
    int count = 0;
    int i = 0;
    // Till \0, which equals to the end of the sentence
    // last year I have used for loop so I tried with while (for is better in this case)
    while (s[i] != '\0')
    {
        // Check if the char is a letter and in that case add one to the counter
        if (isalpha(s[i]))
        {
            count++;
        }
        i++;
    }
    return count;
}

int sentences(string s)
{
    int count = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        // If the char is equal to '.', '?' or '!'
        if (s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            count++;
        }
        i++;
    }
    return count;
}

int words(string s)
{
    // Count starts with one in this case because even
    // if there are no spaces there still is one word
    // at the beginning
    int count = 1;
    int i = 0;
    while (s[i] != '\0')
    {
        // If there is a space I add one to the count
        if (s[i] == ' ')
        {
            count++;
        }
        i++;
    }
    return count;
}
