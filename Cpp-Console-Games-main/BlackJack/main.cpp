#include <iostream>
#include <bits/stdc++.h>
#include <random>


int money = 1000;
int i, j, turn, countingscore;
std::vector < int > cardid;
std::vector < int > randcard;

int playing = 1;

void setup()
{

    for (i = 0; i <= 13; i++)
        {
        cardid.push_back(i);
        //cout << cardid[i] << endl;
        }

        srand(/* time of day or something */ 123);


}

void bet()
{

}

void win()
{
    playing  = 0;
}

void lose()
{
    playing  = 0;
}

void checkconditions()
{
    if (countingscore > 21)
        lose();
    else if (countingscore = 21)
            win(); // for now
}

void deal()
{
        // give two cards to player
            // random between 0 - 14 exclusive
            // add to count face value
            // count ace as 11, but if hit change to 1 if goes over 21
            //
        // cout cards
        // ask if hit or stand

        randcard.push_back(rand()%(14));
        randcard.push_back(rand()%(14));



        //std::cout << randcard[turn] << " and " << randcard[turn+1] << " = " << countingscore << std::endl;

        countingscore = 0;
        for(j=0; j<randcard.size(); j++)
        {
            std::cout << randcard[j] << " | ";
            countingscore += randcard[j];
        } std::cout << " Totals: " << countingscore << std::endl;

        checkconditions();
}

void hit()
{

}

void stand()
{

}

void aihit()
{

}
void aistand()
{

}

int main()
{

    for(int g=0; g<10;g++)
    {
        setup();
        deal();
    }

    return 0;
}
 
