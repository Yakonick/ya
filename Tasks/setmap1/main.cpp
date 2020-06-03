#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> num;
    set<int>::iterator i;
    int temp = 1;
    while (temp != 0)
    {
        cin >> temp;
        num.insert(temp);
    }
    for (i = num.begin(); i != num.end(); i++)
        cout << *i << " ";
}