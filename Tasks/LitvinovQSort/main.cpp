#include <iostream>
#include <vector>

using namespace std;

vector<int> insertsort(vector<int> mass)
{
    for (vector<int>::iterator i = mass.end() - 1; i > mass.begin(); i--)
    {
        for (vector<int>::iterator j = i; j >= mass.begin(); j--)
        {
            if (*i > *j)
            {
                mass.insert(j, *i);
                break;
            }
            else if (j == mass.begin())
            {
                mass.insert(j, *i);
            }
            //cout << *i << " " << *j << endl;
        }
    }
    return mass;
}

/*void quicksort(vector<int> mass)
{
    if (mass.size() < 11)
        insertsort(mass);
    else
    {

    }
}*/

int main()
{
    vector<int> mass {9, 11, 10, 8, 7, 6, 4, 6, 5, 3, 2, 1, 0};
    mass = insertsort(mass);
    for (auto x: mass)
        cout << x << " ";
    cout << endl;
    return 0;
}