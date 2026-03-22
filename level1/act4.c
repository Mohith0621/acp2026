#include <stdio.h>

#define N 11

typedef struct {
    char player_name[50];
    int jersey_number;
    int runs_scored;
} Player;

void readPlayers(int n, Player p[]);
float calculateAverageRuns(int n, Player p[]);

int main()
{
    Player team[N];
    float average;

    readPlayers(N, team);

    average = calculateAverageRuns(N, team);

    printf("\nAverage Runs of the Team: %.2f\n", average);

    return 0;
}

void readPlayers(int n, Player p[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\nPlayer %d:\n", i + 1);

        printf("Enter Player Name: ");
        scanf("%s", p[i].player_name);

        printf("Enter Jersey Number: ");
        scanf("%d", &p[i].jersey_number);

        printf("Enter Runs Scored: ");
        scanf("%d", &p[i].runs_scored);
    }
}

float calculateAverageRuns(int n, Player p[])
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += p[i].runs_scored;
    }

    return (float)total / n;
}