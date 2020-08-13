#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <math.h>
using namespace std;
long double table[2000000] = {0};
int main()
{
    double t = omp_get_wtime();
#pragma omp parallel sections
    {
#pragma omp section
        {
            for(int i = 0; i<1000000; i++) {
                table[2*i + 1] = sin(M_1_PI / (2 * i + 1));
            }
        }
#pragma omp section
        {
            for(int i = 1; i<1000000; i++) {
                table[2*i] = sin(M_1_PI / (2 * i));
            }
        }
    }
    cout<<"Time: "<<omp_get_wtime()-t<<endl;
    for (int i = 0; i < 10; i++)
        cout << i << "\t" << table[i] << endl;
    return EXIT_SUCCESS;
}