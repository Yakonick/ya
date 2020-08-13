#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <math.h>

using namespace std;

const double N = 10000000;

int main()
{
    double sum = 0;

    double t = omp_get_wtime();
    for (int i = 0; i < N; i++)
        sum += 1 / (1 + pow((2 * i - 1) / (2 * N), 2));
    cout << 4 * sum / N << endl;
    cout << omp_get_wtime() - t << endl;

    t = omp_get_wtime();
    sum = 0;
#pragma omp parallel sections reduction(+:sum)
    {
#pragma omp section
        {
            for (int i = 0; i < N / 2; i++)
                sum += 1 / (1 + pow((2 * i - 1) / (2 * N), 2));
        }
#pragma omp section
        {
            for (int i = N / 2; i < N; i++)
                sum += 1 / (1 + pow((2 * i - 1) / (2 * N), 2));
        }
    }
    cout << 4 * sum / N << endl;
    cout << omp_get_wtime() - t << endl;

    return EXIT_SUCCESS;
}