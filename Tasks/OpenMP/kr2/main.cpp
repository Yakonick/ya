#include <iostream>
#include <omp.h>
#include <cstdlib>

using namespace std;

int function(char *A[10000]) {
    int ans = 0;
#pragma omp parallel sections  reduction(+:ans)
    {
#pragma omp section
        {
            for (int i = 0; i < 9998; i += 2) {
                ans += (*A[i] - 48)*10 + *A[i+1] - 48;
#pragma omp atomic
                ans = ans % 17;
            }
        }
#pragma omp section
        {
            for (int i = 0; i < 9998; i += 2) {
                ans += (*A[i] - 48)*10 + *A[i+1] - 48;
#pragma omp atomic
                ans = ans % 17;
            }
        }
    }
    return ans;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}