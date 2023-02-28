#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <random>
#include <ctime>

using namespace std;

int Grid[64][64], nextgen[64][64];
int i,j,l;
int dimension = 50;
int rand_y, rand_x;
int localcellcount[64][64];



void clear_screen ( void ) // https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1031963460&id=1043284385
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

  /* Reset the cursor to the top left position */
  SetConsoleCursorPosition ( h, coord );
}

void render()
{
    //system("cls");
    clear_screen();


    for (i=0; i<dimension+5; i++)
    {
        for (j=0; j<dimension; j++)
        {
            if (Grid[i][j] == 9)
                cout << char(219) << char(219);
            else
                //cout << "  " << localcellcount[i][j] << "  |";
                cout << "  ";
        }
        cout << endl;
    }
}

void setup()
{


    time_t t = std::time(0);
    tm* now = std::localtime(&t);

    int seed = now->tm_sec * now->tm_mday;
    srand(seed);

    //number of starting cells
    for (l=0; l<(350); l++)
    {
        // Need to set srand to the time or something



        rand_y = rand()%(dimension+1);
        rand_x = rand()%(dimension+10);

        Grid[rand_x][rand_y] = 9;
    }
}

void condition()
{
    for (i=0; i<dimension+5; i++)
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
    cout << endl;
    for (i=0; i<dimension+5; i++)
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
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    return 0;
}

