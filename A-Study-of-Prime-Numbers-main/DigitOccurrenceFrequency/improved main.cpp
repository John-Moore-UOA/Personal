#include <iostream>
#include <string>
#include <iomanip>

//using namespace std;

int main()
{
    int num = 1;
    int taskcount, j, digit;

    std::cout << "Count Digits up to X prime: ";
    std::cin >> taskcount;
    system("cls");

        std::string placeholder;

            int one = 0;
            int three = 0;
            int two = 0;
            int four = 0;
            int six = 0;
            int eight = 0;
            int nine = 0;
            int zero = 0;
            int five = 0;
            int seven = 0;

    do
    {
        int isprime = 1;

        placeholder = std::to_string(num);
        char index = placeholder[placeholder.length()-1];
        std::string guide;
        guide = "/0";
        guide.push_back(index);

        if (guide != "/04")
        {
            if (guide != "/06")
            {
                if (guide != "/08")
                {
                    if(guide != "/00")
                    {
                        for (j=2; j<num; j++)
                        {
                            if (num%j == 0)
                                isprime = 0;
                        }
                        if (isprime == 1)
                        {
                            std::cout << "...[" << num << "]";
                            placeholder = std::to_string(num);

                            for (digit=0; digit<=placeholder.length(); digit++)
                            {
                                char index = placeholder[digit];

                                if (index == '1')
                                    one++;
                                else if (index == '2')
                                    two++;
                                else if (index == '3')
                                    three++;
                                else if (index == '4')
                                    four++;
                                else if (index == '5')
                                    five++;
                                else if (index == '6')
                                    six++;
                                else if (index == '7')
                                    seven++;
                                else if (index == '8')
                                    eight++;
                                else if (index == '9')
                                    nine++;
                                else if (index == '0')
                                zero++;
                            }
                        } else
                            std::cout << "..." << num;
                    } else
                        std::cout << "..." << num;
                } else
                    std::cout << "..." << num;
            } else
                std::cout << "..." << num;
        } else
            std::cout << "..." << num;

    num++;
    } while (num <= taskcount);

    std::cout << std::endl << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << "...Count [One]  " << std::setw(10) << ":" << std::setw(10) << one << std::endl;
    std::cout << "...Count [Two]  " << std::setw(10) << ":" << std::setw(10) << two << std::endl;
    std::cout << "...Count [Three]" << std::setw(10) << ":" << std::setw(10) << three << std::endl;
    std::cout << "...Count [Four] " << std::setw(10) << ":" << std::setw(10) << four << std::endl;
    std::cout << "...Count [Five] " << std::setw(10) << ":" << std::setw(10) << five << std::endl;
    std::cout << "...Count [Six]  " << std::setw(10) << ":" << std::setw(10) << six << std::endl;
    std::cout << "...Count [Seven]" << std::setw(10) << ":" << std::setw(10) << seven << std::endl;
    std::cout << "...Count [Eight]" << std::setw(10) << ":" << std::setw(10) << eight << std::endl;
    std::cout << "...Count [Nine] " << std::setw(10) << ":" << std::setw(10) << nine << std::endl;
    std::cout << "...Count [Zero] " << std::setw(10) << ":" << std::setw(10) << zero << std::endl;

    return 0;
}
