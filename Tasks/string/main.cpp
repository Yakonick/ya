#include <iostream>
#include <cctype>

using namespace std;

int number_of_digital(char *string1)
{
    int i = 0, number = 0;
    while (string1[i] != 0)
    {
        if (isdigit(string1[i]) and !(isdigit(string1[i + 1])))
            ++number;
        ++i;
    }
    return number;
}


int main()
{
    char *string1 = "lsuihv728uhwivjks8sv7uihj3qoi89ewruyhj34";
    cout << endl << number_of_digital(string1) << endl;
    return 0;
}