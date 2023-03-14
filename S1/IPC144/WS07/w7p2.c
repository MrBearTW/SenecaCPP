/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  :CHI-WEI PERNG
Student ID#:121967228
Email      :cperng@myseneca.ca
Section    :NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LIVES 10
#define MINI_LIVES 1
#define MAX_PATH_LENGTH 70
#define MINI_PATH_LENGTH 10
#define MOVES_REMAINING 10

#include <stdio.h>

struct PlayerInfo
{
    char playerRepresent;
    int lives;
    int treasure;
    int history[MOVES_REMAINING];
    int position;
};

struct GameInfo
{
    int moves;
    int pathlength;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
    int visited[MAX_PATH_LENGTH];
};

int main(void)
{
    struct PlayerInfo p1 = {0};
    struct GameInfo g1 = {0};
    int movesMax, movesMini, i, inputPosition;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &p1.playerRepresent);
    do
    {
        printf("Set the number of lives: ");
        scanf(" %d", &p1.lives);
        (p1.lives < MINI_LIVES || p1.lives > MAX_LIVES) ? printf("     Must be between 1 and 10!\n") : printf("Player configuration set-up is complete\n");
    } while (p1.lives < MINI_LIVES || p1.lives > MAX_LIVES);

    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf(" %d", &g1.pathlength);
        if (g1.pathlength < MINI_PATH_LENGTH || g1.pathlength > MAX_PATH_LENGTH || (g1.pathlength % 5 != 0))
            printf("     Must be a multiple of 5 and between 10-70!!!\n");

    } while (g1.pathlength < MINI_PATH_LENGTH || g1.pathlength > MAX_PATH_LENGTH || (g1.pathlength % 5 != 0));
    movesMini = p1.lives;
    movesMax = (int)(g1.pathlength * 0.75);
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf(" %d", &g1.moves);

        if (g1.moves < movesMini || g1.moves > movesMax)
            printf("    Value must be between %d and %d\n", movesMini, movesMax);

    } while (g1.moves < movesMini || g1.moves > movesMax);
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.pathlength);
    for (i = 0; i < g1.pathlength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d%d%d%d%d", &g1.bombs[i], &g1.bombs[i + 1], &g1.bombs[i + 2], &g1.bombs[i + 3], &g1.bombs[i + 4]);
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.pathlength);
    for (i = 0; i < g1.pathlength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d%d%d%d%d", &g1.treasure[i], &g1.treasure[i + 1], &g1.treasure[i + 2], &g1.treasure[i + 3], &g1.treasure[i + 4]);
    }
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", p1.playerRepresent);
    printf("   Lives      : %d\n", p1.lives);
    printf("   Treasure   : ");
    (p1.treasure == 0) ? printf("[ready for gameplay]\n") : printf("%d\n", p1.treasure);
    printf("   History    : ");
    (p1.history[0] == 0) ? printf("[ready for gameplay]\n") : printf("%d\n", p1.history[0]);
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", g1.pathlength);
    printf("   Bombs      : ");
    for (i = 0; i < g1.pathlength; i++)
        printf("%d", g1.bombs[i]);
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < g1.pathlength; i++)
        printf("%d", g1.treasure[i]);
    printf("\n");
    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    while (p1.lives != -1 && g1.moves != 0)
    {
        // print current board status
        if (p1.lives >= 0)
        {
            printf("%c%c", 0, 0);
            for (i = 1; i < g1.pathlength + 1; i++)
            {
                if (p1.position == i)
                {
                    printf("%c", p1.playerRepresent);
                }
                else
                {
                    printf("%c", 0);
                }
            }
            printf("\n");
            printf("  ");
            for (i = 0; i < g1.pathlength; i++)
            {
                switch (g1.visited[i])
                {
                case 1:
                    printf("!");
                    break;
                case 2:
                    printf("$");
                    break;
                case 3:
                    printf("&");
                    break;
                case 4:
                    printf(".");
                    break;

                default:
                    printf("-");
                    break;
                }
            }
            printf("\n");
            printf("  ");
            for (i = 1; i < g1.pathlength + 1; i++)
            {
                if (i % 10 == 0)
                {
                    printf("%d", i % 10);
                }
                else
                {
                    printf("|");
                }
            }
            printf("\n");
            printf("  ");
            for (i = 1; i < g1.pathlength + 1; i++)
            {
                printf("%d", i % 10);
            }
            printf("\n");
            printf("+---------------------------------------------------+\n");
            printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", p1.lives, p1.treasure, g1.moves);
            printf("+---------------------------------------------------+\n");
            // print last time
            if (p1.lives == 0)
            {
                p1.lives--;
            }
        }
        if (p1.lives > 0)
        {
            // print Next Move input
            do
            {
                printf("Next Move [1-%d]: ", g1.pathlength);
                scanf("%d", &inputPosition);
                if (inputPosition < 1 || inputPosition > g1.pathlength)
                {
                    printf("  Out of Range!!!\n");
                }
            } while (inputPosition < 1 || inputPosition > g1.pathlength);
            // print Next Move result
            g1.moves--;
            p1.position = inputPosition;
            printf("\n");
            if (g1.visited[p1.position - 1] == 4)
            {
                printf("===============> Dope! You've been here before!\n");
            }
            else
            {
                if (g1.bombs[p1.position - 1] == 1 && g1.treasure[p1.position - 1] == 1)
                {
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                    g1.visited[p1.position - 1] = 3;
                    p1.lives--;
                    p1.treasure++;
                }
                else if (g1.bombs[p1.position - 1] == 1)
                {
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                    g1.visited[p1.position - 1] = 1;
                    p1.lives--;
                }
                else if (g1.treasure[p1.position - 1] == 1)
                {
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                    g1.visited[p1.position - 1] = 2;
                    p1.treasure++;
                }
                else
                {
                    printf("===============> [.] ...Nothing found here... [.]\n");
                    g1.visited[p1.position - 1] = 4;
                }
            }
        }
        printf("\n");
    }
    // print ending
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}
