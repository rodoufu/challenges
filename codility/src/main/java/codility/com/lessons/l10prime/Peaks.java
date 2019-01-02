package codility.com.lessons.l10prime;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * 100 + 20 = 63
 * @author rodolfo
 */
public class Peaks {
	public int solution(int[] A) {
		if (A.length < 3) {
			return 0;
		}
		int peaks[] = new int[A.length];
		peaks[0] = 0;
		for (int i = 1; i < A.length - 1; i++) {
			peaks[i] = peaks[i - 1];
			if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
				peaks[i]++;

				// Não precisa testar o próximo
				peaks[i + 1] = peaks[i];
				i++;
			}
		}
		peaks[A.length - 1] = peaks[A.length - 2];
		if (peaks[A.length - 1] <= 1 || peaks[A.length - 1] == A.length || peaks[A.length - 1] == 0) {
			return peaks[A.length - 1];
		}

		List<Integer> iterate = new ArrayList<>();
		{
			Set<Integer> factors = factors(A.length);
			for (int x : factors) {
				if (x <= peaks[A.length - 1]) {
					iterate.add(x);
				}
			}
			factors = null;
		}
		iterate.sort((x, y) -> Integer.compare(y, x));
		for (int x : iterate) {
			// System.out.println(x);

			boolean resposta = true;
			int NdivX = A.length / x;
			for (int i = 0; resposta && i < x; i++) {
				resposta = peaks[(i + 1) * NdivX - 1] > peaks[Math.max(i * NdivX - 1, 0)];
			}
			if (resposta) {
				return x;
			}
		}
		return 0;
	}

	private Set<Integer> factors(int n) {
		Set<Integer> set = new HashSet<>();
		final int sqrtN = (int) Math.sqrt(n);
		for (int i = 1; i <= sqrtN; i++) {
			if (n % i == 0) {
				set.add(i);
				set.add(n / i);
			}
		}
		return set;
	}
}
