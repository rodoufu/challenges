#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n < 1) {
        return 1;
    }
    int fib[] = {0, 0, 1};
    for (int i = 1; i < n; ++i) {
        fib[0] = fib[1];
        fib[1] = fib[2];
        fib[2] = fib[0] + fib[1];
    }
    return fib[2];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
