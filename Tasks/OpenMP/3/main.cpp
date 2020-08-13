#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <math.h>
using namespace std;

int main() {
    long int n;
    int ans = 0, tmp = 1, tmp2 = 1;
    cin >> n;
    double t = omp_get_wtime();
    for (int i = 3; i <= n; i += 2) {
        tmp = 1;
        for (int j = 3; j <= sqrt(i) + 1; j += 2) {
            if (i % j == 0) {
                tmp = 0;
                break;
            }
        }
        if (tmp == 1) {
            ans++;
        }
    }
    cout << "Time: " << omp_get_wtime() - t << endl;
    cout << "Answer: " << ans + 1 << endl;


    ans = 0; tmp = 1;
    t = omp_get_wtime();
#pragma omp parallel sections reduction(+:ans)
    {
#pragma omp section
        {
            for (int i = 3; i <= n / 2; i += 2) {
                tmp = 1;
                for (int j = 3; j <= sqrt(i) + 1; j += 2) {
                    if (i % j == 0) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp == 1) {
                    ans++;
                }
            }
        }
#pragma omp section
        {
            for (int i = (n / 2) + 1 - ((n/2)%2); i <= n; i += 2) {
                tmp2 = 1;
                for (int j = 3; j <= sqrt(i) + 1; j += 2) {
                    if (i % j == 0) {
                        tmp2 = 0;
                        break;
                    }
                }
                if (tmp2 == 1) {
                    ans++;
                }
            }
        }
    }
    cout << "Time: " << omp_get_wtime() - t << endl;
    cout << "Answer: " << ans + 1 << endl;


    ans = 0, tmp = 1;
    t = omp_get_wtime();
#pragma omp parallel for schedule(guided) reduction(+:ans) private(tmp)
    for (int i = 3; i <= n; i += 2) {
        tmp = 1;
        for (int j = 3; j <= sqrt(i) + 1; j += 2) {
            if (i % j == 0) {
                tmp = 0;
                break;
            }
        }
        if (tmp == 1) {
            ans++;
        }
    }

    cout << "Time: " << omp_get_wtime() - t << endl;
    cout << "Answer: " << ans + 1 << endl;

    return EXIT_SUCCESS;
}
