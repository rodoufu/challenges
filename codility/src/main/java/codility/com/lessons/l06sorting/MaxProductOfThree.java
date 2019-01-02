package codility.com.lessons.l06sorting;

import java.util.Arrays;

/**
 * 100%
 * @author 08115341622
 */
public class MaxProductOfThree {
	public int solution(int[] A) {
		Arrays.sort(A);
		return Math.max(Math.max(A[0] * A[1] * A[2], A[A.length - 1] * A[A.length - 2] * A[A.length - 3]), A[0] * A[1] * A[A.length - 1]);
    }
}
