#include <iostream>
#include <omp.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

int function(char *A[10000]) {
    int ans = 0;
#pragma omp parallel sections
    {
#pragma omp section
        {
            int tmp1;
            for (int i = 0; i < 10000; i+= 16) {
                 tmp1 = atoi(A[i]) * 12 + atoi(A[i+1]) * 8 + atoi(A[i+2]) * 11 + atoi(A[i+3]) * 13 + atoi(A[i+4]) * 3 + atoi(A[i+5]) * 2 + atoi(A[i+6]) * 7 + atoi(A[i+7]) * 16;
#pragma omp atomic
                 ans += (tmp1 % 17);
            }
        }
#pragma omp section
        {
            int tmp2;
            for (int i = 8; i < 10000; i+= 16) {
                tmp2 = atoi(A[i]) * 5 + atoi(A[i+1]) * 9 + atoi(A[i+2]) * 6 + atoi(A[i+3]) * 4 + atoi(A[i+4]) * 14 + atoi(A[i+5]) * 15 + atoi(A[i+6]) * 10 + atoi(A[i+7]);
#pragma omp atomic
                ans += (tmp2 % 17);
            }
        }
    }
    return (ans % 17);
}
int main() {

    return 0;
}
