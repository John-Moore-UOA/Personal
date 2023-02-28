#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

int Grid[64][64], nextgen[64][64];
int i,j,l;
int dimension = 20;
int rand_y, rand_x;
int localcellcount[64][64];


void render()
{
    system("cls");

    for (i=0; i<dimension+10; i++)
    {
        for (j=0; j<dimension; j++)
        {
            if (Grid[i][j] == 9)
                cout << " OOO |";
            else
                //cout << "  " << localcellcount[i][j] << "  |";
                cout << "     |";
        }
        cout << endl;
    }
}

void setup()
{
    //number of starting cells
    for (l=0; l<(150); l++)
    {
        srand(rand());
        rand_y = rand()%(dimension+1);
        rand_x = rand()%(dimension+10);

        Grid[rand_x][rand_y] = 9;
    }
}

void condition()
{
    for (i=0; i<dimension+10; i++)
    {
        for (j=0; j<dimension; j++)
        {
            localcellcount[i][j] = 0;

            if (Grid[i][j] == 9)
            {
                if (Grid[i+1][j] == 9)
                    localcellcount[i][j]++;

                if (Grid[i+1][j+1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i+1][j-1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i-1][j] == 9)
                    localcellcount[i][j]++;

                if (Grid[i-1][j+1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i-1][j-1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i][j+1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i][j-1] == 9)
                    localcellcount[i][j]++;

            } else if (Grid[i][j] != 9)
            {
                if (Grid[i+1][j] == 9)
                    localcellcount[i][j]++;

                if (Grid[i+1][j+1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i+1][j-1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i-1][j] == 9)
                    localcellcount[i][j]++;

                if (Grid[i-1][j+1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i-1][j-1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i][j+1] == 9)
                    localcellcount[i][j]++;

                if (Grid[i][j-1] == 9)
                    localcellcount[i][j]++;

                Grid[i][j] = localcellcount[i][j];
            }

            //Birth of a cell
            if (localcellcount[i][j] == 3)
                nextgen[i][j] = 9;

            //Live
            if (Grid[i][j] == 9)
            {
                if (localcellcount[i][j] == 2 || localcellcount[i][j] == 3)
                    nextgen[i][j] = 9;
                else
                    nextgen[i][j] = 0;
            } else if (localcellcount[i][j] == 3)
                    nextgen[i][j] = 9;
        }
    }
    printf("\n");
    for (i=0; i<dimension+10; i++)
    {
        for (j=0; j<dimension; j++)
        {
            Grid[i][j] = nextgen[i][j];
        }
    }
}

int main()
{
    setup();
    while(1)
    //for (int y=0; y<10; y++)
    {
        condition();
        render();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}
