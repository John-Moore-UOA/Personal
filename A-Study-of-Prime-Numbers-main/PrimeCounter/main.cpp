#include <iostream>

using namespace std;

int main()
{
    int num;
    int notprime, i, k, counter = 0;

    cout << "To What Number: ";
    cin >> num;

    for (k=0; k<num; k++)
    {
        for (i=2; i<k; i++)
        {
            if (k % i == 0)
            {
                notprime += 1;
            }
        }
        if (notprime == 0)
        {
            counter ++;
            cout << k << "\n";
        }
        notprime = 0;
    }

    float primecount = counter-2;
    float percentage = primecount/num;

    cout << "\n\nNumber Of Primes: " << primecount;
    cout << "\nThat is: " << percentage << " | " << percentage*100 << "%";
    return 0;
}
