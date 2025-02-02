#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string word);
string to_upper(string s);

int main(void)
{
    // Declare the scores of the players
    int score1;
    int score2;

    // Prompt the user for the word
    string word1 = get_string("Word from player 1: ");
    string word2 = get_string("Word from player 2: ");

    // Upper every word so it's easier to check the char and calculate the score
    word1 = to_upper(word1);
    word2 = to_upper(word2);

    // Recall the function and assign the return value to the variable score
    score1 = calculate_score(word1);
    // The same for player two
    score2 = calculate_score(word2);

    // Determine the winner comparing the scores I've stored from my function calculate_score
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    // If the score of player 2 is greater, player 2 wins
    else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }
    // or the tie
    else
    {
        printf("Tie!\n");
    }
}

int calculate_score(string word)
{
    int score = 0;
    int i = 0;
    while (word[i] != '\0')
    {
        // if the char is equal to a particular char then a certain score is added
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'L' ||
            word[i] == 'N' || word[i] == 'O' || word[i] == 'R' || word[i] == 'S' ||
            word[i] == 'T' || word[i] == 'U')
        {
            score += 1;
        }
        else if (word[i] == 'D' || word[i] == 'G')
        {
            score += 2;
        }
        else if (word[i] == 'B' || word[i] == 'C' || word[i] == 'M' || word[i] == 'P')
        {
            score += 3;
        }
        else if (word[i] == 'F' || word[i] == 'H' || word[i] == 'V' || word[i] == 'W' ||
                 word[i] == 'Y')
        {
            score += 4;
        }
        else if (word[i] == 'K')
        {
            score += 5;
        }
        else if (word[i] == 'J' || word[i] == 'X')
        {
            score += 8;
        }
        else if (word[i] == 'Q' || word[i] == 'Z')
        {
            score += 10;
        }
        else
        {
            score += 0;
        }
        i++;
    }
    return score;
}

string to_upper(string s)
{
    int length = strlen(s);
    // Upper every char
    for (int i = 0; i < length; i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}
