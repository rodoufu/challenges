package codility.com.lessons.l06sorting;

import java.util.Arrays;

/**
 * 100%
 * @author 08115341622
 */
public class Triangle {
	public int solution(int[] A) {
		long Al[] = new long[A.length];
		for (int i = 0; i < A.length; i++) {
			Al[i] = A[i];
		}
		Arrays.sort(Al);
		for (int i = 0; i < A.length - 2; i++) {
			if (Al[i] + Al[i + 1] > Al[i + 2]) {
				return 1;
			}
		}
		return 0;
	}
}
