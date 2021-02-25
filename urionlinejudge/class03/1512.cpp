// https://www.urionlinejudge.com.br/judge/pt/problems/view/1512
#include <cstdio>

template<class IntType>
IntType gcd(IntType a, IntType b) {
	return b == 0 ? a : gcd(b, a % b);
}

using IntPrec = unsigned long long;

int main() {
	IntPrec n, a, b;
	for (;;) {
		scanf("%llu%llu%llu", &n, &a, &b);
		if (n == a && a == b && b == 0) {
			break;
		}
		printf("%llu\n", n / a + n / b - n / (a * b / gcd(a, b)));
	}

	return 0;
}
