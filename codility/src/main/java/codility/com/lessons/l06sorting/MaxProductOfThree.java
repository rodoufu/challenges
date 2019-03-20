package codility.com.lessons.l06sorting;

import java.util.Arrays;

/**
 * 100%
 * https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
 */
public class MaxProductOfThree {
	public int solution(int[] A) {
		Arrays.sort(A);
		return Math.max(Math.max(A[0] * A[1] * A[2], A[A.length - 1] * A[A.length - 2] * A[A.length - 3]), A[0] * A[1] * A[A.length - 1]);
    }
}
