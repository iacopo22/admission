#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");

    // Score both words
    int score1 = compute_score(word1);


    // TODO: Print the winner
}

int compute_score(string word)
{
	// TODO: Compute and return score for string
	int score = 0;
	for (int i = 0, n = strlen(word); i < n; i++)
	{
		if (isupper(word[i]))
		{
			int points_upper = POINTS[word[i] - 65];
			printf("Points of that char: %i\n", points_upper);
			score += points_upper;
		}
		else if (islower(word[i]))
		{
			int points_lower = POINTS[word[i] - 97];
			printf("Points of that char: %i\n", points_lower);
			score += points_lower;
		}
		printf("Score: %i\n", score);
	}
	printf("\n");
	return 0;

}
