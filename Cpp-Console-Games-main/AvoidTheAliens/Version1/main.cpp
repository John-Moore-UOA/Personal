#include <iostream>

using namespace std;


int y = 3, x = 3;
int ali_x = 5, ali_y = 5;
int close, score;


void conditions(int x, int y, int ali_x, int ali_y)
{
    if (x == ali_x && y == ali_y)
    {
        close = 1;
        system("cls");
        cout << "...GAME OVER...RETURNED SCORE BELOW...";
    }



}

void render(int x, int y, int ali_x, int ali_y)
{
    int i,j,k;
    int dimensions = 9;

    int field[9][9];
    if (y < dimensions && x < dimensions )
        if (y >= 0 && x >= 0)
        {
            for (i=0; i<dimensions; i++)
            {
                for (j=0; j<dimensions; j++)
                {
                    field[i][j] = 0;
                }
            }
            field[y][x] = 1;
        }

        field[ali_y][ali_x] = 2;
        //cout << ali_x << " " << ali_y << endl;
        // fix the wrap bug

    system("cls");

    for(i=0; i<dimensions; i++)
    {
        for (j=0; j<dimensions; j++)
        {
            if (field[i][j] == 1)
                cout << "|SPH";
            else
                if (field[i][j] == 2)
                    cout << "|ALI";
                else
                    cout << "|   ";
        }
        cout << "|" << endl << "|---|---|---|---|---|---|---|---|---|" << endl;
    }
    conditions(x,y, ali_x, ali_y);


}

void setup()
{
    render(x,y, ali_x, ali_y);
}

void movefunction(int direction)
{

    switch(direction)
    {
    case 'w':
        y -= 1;
        break;
    case 'a':
        x -= 1;
        break;
    case 's':
        y += 1;
        break;
    case 'd':
        x += 1;
        break;
    }


    if (ali_x < 8)
    {
        ali_x ++;
    } else
        ali_x = 0;

    if (ali_y < 8)
    {
        ali_y ++;
    } else
        ali_y = 0;


    if (ali_x == x )
    {
        if (ali_x > x)
            ali_y++;
        else
            ali_y--;
    }

    render(x,y, ali_x, ali_y);
}


int main()
{
    setup();

    int score;
    char direction;
    do {
            cout << "WASD: ";
            cin >> direction;
            movefunction(direction);
            score++;
    } while(close != 1);

    return score;
}
