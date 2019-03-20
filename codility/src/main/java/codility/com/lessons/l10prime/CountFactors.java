package codility.com.lessons.l10prime;

// https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/
public class CountFactors {
	public int solution(int N) {
		int contar = 0;
		final int sqrtN = (int) Math.sqrt(N);
		for (int i = 1; i <= sqrtN; i++) {
			if (N % i == 0) {
				contar += i != (N / i) ? 2 : 1; 
			}
			//System.out.printf("i: %d, sqrt(N): %d, i*i: %d, N: %d, contar: %d\n", i, sqrtN, i*i, N, contar);
		}
		return contar;
	}
}
