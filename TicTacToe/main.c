#include <stdio.h>
#include <stdlib.h>


int Grid[4][4];
int i, j, k, l;
int dimension = 3;
int move_y, move_x;
int player = 1;
int winner;
int Conditional_valueONE, Conditional_valueTWO, Condition_Draw;

void Render()
{
    system("cls");
    for (i=0; i<dimension; i++)
    {
        for (j=0; j<dimension; j++)
        {
            printf("  %d  |", Grid[i][j]);
        }
        printf("\n", Grid[i][j]);
    }
}

void verify()
{
    if (Grid[move_y-1][move_x-1] == 0)
    {
        place();
    } else
    {
        printf("\nPlacement Error\n");
    }
}

void place()
{
    Grid[move_y-1][move_x-1] = player;
    Render();

    if(player == 1)
    {
        player = 2;
    } else
    {
        player = 1;
    }

    //Draw condition
    Condition_Draw = 0;
    for (i=0; i<dimension; i++)
    {
        for (j=0; j<dimension; j++)
        {
            if (Grid[i][j] == 0) {
                Condition_Draw += 1;
            }
        }
    }
    if (Condition_Draw == 0) {
        gameover(0);
    }
}

void condition()
{
    for (i=0; i<dimension; i++)
    {
        Conditional_valueONE = 0;
        Conditional_valueTWO = 0;
        for (k=0; k<dimension; k++)
        {
            if (Grid[i][k] != 0 && Grid[i][k] != 2)
            {
                Conditional_valueONE += 1;
            }

            if (Grid[i][k] != 0 && Grid[i][k] != 1)
            {
                Conditional_valueTWO += 1;
            }

            if (Conditional_valueONE == dimension)
            {
                gameover(1);
                break;
            } else if (Conditional_valueONE == dimension)
            {
                gameover(2);
                break;
            }
        }
    }

    for (i=0; i<dimension; i++)
    {
        Conditional_valueONE = 0;
        Conditional_valueTWO = 0;
        for (k=0; k<dimension; k++)
        {
            if (Grid[k][i] != 0 && Grid[k][i] != 2)
            {
                Conditional_valueONE += 1;
            } else
            {
                Conditional_valueONE = 0;
            }

            if (Grid[k][i] != 0 && Grid[k][i] != 1)
            {
                Conditional_valueTWO += 1;
            } else
            {
                Conditional_valueTWO = 0;
            }

            if (Conditional_valueONE == dimension)
            {
                gameover(1);
                break;
            } else if (Conditional_valueONE == dimension)
            {
                gameover(2);
                break;
            }
        }
    }

    //  Should update that extends to higher dimensions
    if (Grid[0][0] == 1 && Grid[1][1] == 1 && Grid[2][2] == 1)
    {
        gameover(1);
    }
    if (Grid[2][0] == 1 && Grid[1][1] == 1 && Grid[0][2] == 1)
    {
        gameover(1);
    }

    if (Grid[0][0] == 2 && Grid[1][1] == 2 && Grid[2][2] == 2)
    {
        gameover(2);
    }
    if (Grid[2][0] == 2 && Grid[1][1] == 2 && Grid[0][2] == 2)
    {
        gameover(2);
    }
}

void gameover(int winner)
{
    if (winner == 0)
    {
        printf("\n\nGame Over: Draw\n", winner);
    } else
    {
        printf("\n\nGame Over: Player %d Wins\n", winner);
    }
    exit(0);
}

int main()
{
    Render();
    while(1)
    {
        printf("Player %d's Move (Column, Row): ", player);
        scanf("%d %d", &move_y, &move_x);
        verify();
        condition();
    }
    return 0;
}
