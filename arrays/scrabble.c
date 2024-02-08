#include <cs50.h>
#include <stdio.h>
#include <string.h>

// scrabble scores
// A: 1, B: 3, C: 3, D: 2, E: 1, F: 4, G: 2, H: 4, I: 1, J: 8, K: 5, L: 1, M: 3, N: 1, O: 1, P: 3, Q: 10, R: 1, S: 1, T: 1, U: 1, V:
// 4, W: 4, X: 8, Y: 4, Z: 10

int calculate_sore(string word, int scores[])
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            score += scores[word[i] - 'A'];
        }
        else if (word[i] >= 'a' && word[i] <= 'z')
        {
            score += scores[word[i] - 'a'];
        }
    }
    return score;
}

int main(void)
{
    // assign scores to letters
    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // get word from user1
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // calculate scores
    int score1 = 0;
    int score2 = 0;

    score1 = calculate_sore(player1, scores);
    score2 = calculate_sore(player2, scores);

    // print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}