#include <map>
#include <limits>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

#include <math.h>

using namespace std;

int main() {
    int testes;
    int n, i;
    double p;
    scanf("%d", &testes);
    for (int count = 0; count < testes; ++count) {
        scanf("%d%lf%d", &n, &p, &i);
        if (p == 0 || n == 0) {
            puts("0.0000");
        } else {
            printf("%.4lf\n", p * pow(1 - p, i - 1) / (1 - pow(1 - p, n)));
        }
    }

    return 0;
}
