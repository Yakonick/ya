#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    stack<double> Stack;
    string LineOfNumbers;
    getline(cin, LineOfNumbers);
    char Char, B; double Num;

    for (int i = 0; i < LineOfNumbers.size(); i++)
    {
        if ((char)LineOfNumbers[i] > 47 && (char)LineOfNumbers[i] < 58)
        {
            Num = Num * 10 + (char)LineOfNumbers[i] - 48;
            if (LineOfNumbers[i+1] == ' ')
            {
                Stack.push(Num);
                Num = 0;
            }
        }
        else if (LineOfNumbers[i] == '+')
        {
            double Temp1 = Stack.top(), Temp2;
            Stack.pop();
            Temp2 = Stack.top();
            Stack.pop();
            Stack.push(Temp1 + Temp2);
        }
        else if (LineOfNumbers[i] == '-')
        {
            double Temp1 = Stack.top(), Temp2;
            Stack.pop();
            Temp2 = Stack.top();
            Stack.pop();
            Stack.push(Temp1 - Temp2);
        }
        else if (LineOfNumbers[i] == '*')
        {
            double Temp1 = Stack.top(), Temp2;
            Stack.pop();
            Temp2 = Stack.top();
            Stack.pop();
            Stack.push(Temp1 * Temp2);
        }
        else if (LineOfNumbers[i] == '/')
        {
            double Temp1 = Stack.top(), Temp2;
            Stack.pop();
            Temp2 = Stack.top();
            Stack.pop();
            Stack.push(Temp1 / Temp2);
        }
    }

    cout << Stack.top() << endl;

    return 0;
}