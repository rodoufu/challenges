package codility.com.lessons.l12euclideanalgorithm;

/**
 * 100%
 * https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/
 */
public class ChocolatesByNumbers {
	public int solution(int N, int M) {
		return (int) (mmc(N, M) / M);
	}

	public long mmc(long a, long b) {
		return a * b / mdc(a, b);
	}

	public long mdc(long a, long b) {
		if (a % b == 0) {
			return b;
		} else {
			return mdc(b, a % b);
		}
	}
}
