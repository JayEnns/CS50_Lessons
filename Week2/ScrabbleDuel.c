#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// LETTERS:     a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q   r  s  t  u  v  w  x  y  z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// INDEX:       0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16  17 18 19 20 21 22 23 24 25

int compute_score(char word[]);

int main(void)
{
    // Get input words from both players
    char word1[17], word2[17]; 
    printf("Player 1: ");
    fgets(word1, 17, stdin);

    printf("Player 2: ");
    fgets(word2, 17, stdin);

    word1[strcspn(word1, "\n")] = 0;
    word2[strcspn(word2, "\n")] = 0;

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("%s = %i points\n", word1, score1);
    printf("%s = %i points\n", word2, score2);

    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("TIE\n");
    }
}

int compute_score(char word[])
{
    // TODO: Compute and return score for string
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if ((word[i] >= 65) && (word[i] <= 90)) // uppercase check
        {
            score += POINTS[word[i] - 65];
        }
        else
        {
            score += POINTS[word[i] - 97];
        }
    }
    return score;
}
