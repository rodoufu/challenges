package codility.com.lessons.l09maxsliceproblem;

/**
 * 100%
 * https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
 */
public class MaxProfit {
	public int solution(int[] A) {
		if (A.length < 2) {
			return 0;
		}

		int max_ending = 0;
		int max_slice = 0;
		int min = A[0];
		for (int i = 1; i < A.length; i++) {
			max_ending = Math.max(0, A[i] - min);
			min = Math.min(min, A[i]);
			max_slice = Math.max(max_slice, max_ending);
		}
		return max_slice;
	}
}
