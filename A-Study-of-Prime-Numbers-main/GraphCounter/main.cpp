#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    #define DIM 19
    int count[100];
    int blocks[100];
    vector <int>arr;
    string str;

    int sum;
    float average;
    int max = 0;

    int range_from, range;
    cout << "(weird exclusive-ish) Enter Range: (X-Y): ";
    cin >> range_from >> range;

    bool shown_prime = false;

    if (range_from > range) {
        int temp = range_from;
        range_from = range;
        range = temp;
    }

    bool is_prime;
    for (int num=range_from; num<range; num++) {
        if (num%((int)(range/10)) == 0) {
                    cout << "." << to_string(num)[0] << ".";
                }
        if (!(num > 10 && num%2 == 0)) {
            if (abs(range-range_from) > 10) {

            }

            is_prime = true;
            for (int i=2; i<num; i++) {
                if (num%i == 0)
                    is_prime = false;
            }

            if (is_prime) {
                    if (!shown_prime) {
                        cout << endl << "First Prime: " << num << endl << endl;
                        shown_prime = true;
                    }

                for (int i=0; i<to_string(num).length(); i++) {
                    arr.push_back((num / (int)pow(10, to_string(num).length()-1-i))%10);
                }

                for (int i=0; i<10; i++)
                    count[i] = 0;

                for (int i=0; i<arr.size(); i++) {
                    switch(arr[i]) {
                        case 0:
                            count[0]++;
                            break;
                        case 1:
                            count[1]++;
                            break;
                        case 2:
                            count[2]++;
                            break;
                        case 3:
                            count[3]++;
                            break;
                        case 4:
                            count[4]++;
                            break;
                        case 5:
                            count[5]++;
                            break;
                        case 6:
                            count[6]++;
                            break;
                        case 7:
                            count[7]++;
                            break;
                        case 8:
                            count[8]++;
                            break;
                        case 9:
                            count[9]++;
                            break;
                    }
                }
            }
        }
    }
    if (range_from-range > 100) {
        cout << ".Done" << endl;
    }

    for (int i=0; i<10; i++) {
        sum += count[i];
    }
    average = sum / 10.0;



    for (int i=0; i<10; i++) {
        if (max < count[i] ) {
            max = count[i];
        }
    }

    float sway = 18/((float)max/(average+1));

    cout << endl;
    for (int i=0; i<10; i++) {
        blocks[i] = (int)(sway*(count[i]/(average+1)));
        cout << i << " : " << count[i] << " : " << (int)((count[i]/(float)sum)*100) << "%" << endl;
    } cout << endl <<"Total Prime Digits Counted: " << sum << endl << endl;

    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
                if (j%2 == 0) {
                    if (blocks[j/2] >= 18-i) {
                        cout << char(219) << char(219) << char(219) << "|";
                    } else cout << "   |";
                } else cout << "   |";
        } cout << endl;
    }

    for (int i=0; i<DIM; i++) {
        if (i%2 == 0)
            cout << " " << i/2 << " |";
        else cout << "   |";
    }
    #undef DIM

    return 0;
}
