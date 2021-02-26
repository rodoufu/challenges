// https://www.urionlinejudge.com.br/judge/pt/problems/view/1537
#include <cstdio>

using IntPrec = unsigned long long;
const IntPrec fixValue = 1000000009;

int main() {
	IntPrec n;
	for (;;) {
		scanf("%llu", &n);
		if (n == 0) {
			break;
		} else if (n == 3) {
			puts("1");
		} else {
			IntPrec pos = 3, resp = 1;
			for (IntPrec i = n - 3; i > 0; --i) {
				resp = (resp * (pos + 1)) % fixValue;
				pos += 1;
			}
			printf("%llu\n", resp);
		}
	}

	return 0;
}
