#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std;

int function(int A[2500]) {
    int ans = 0;
#pragma omp parallel sections reduction(+:ans)
    {
#pragma omp section
        {
            for (int i = 0; i <= 1125; i++) {
                if (A[i + 1] < A[i])
                    ans++;
            }
        }
#pragma omp section
        {
            for (int i = 1126; i < 2499; i++) {
                if (A[i + 1] < A[i])
                    ans++;
            }
        }
    }
    return ans;
}


int main() {


    return EXIT_SUCCESS;
}
