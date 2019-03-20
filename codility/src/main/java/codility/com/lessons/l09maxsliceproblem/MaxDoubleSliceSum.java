package codility.com.lessons.l09maxsliceproblem;

import java.util.Arrays;

//https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/
public class MaxDoubleSliceSum {
	public int solution(int[] A) {
		long menores[] = new long[4];
		long soma[] = new long[A.length];
		long somaSlice[] = new long[A.length];
		long max = 0;
		for (int i = 0; i < 4; i++) {
			menores[i] = Integer.MAX_VALUE;
		}
		
		for (int i = 1; i < A.length; i++) {
			if (i > 1 && A[i - 1] < menores[2]) {
				menores[3] = A[i - 1];
				Arrays.sort(menores);
			}
			soma[i] = soma[i - 1] + A[i];
			if (soma[i] < 0) {
				somaSlice[i] = somaSlice[i - 1] + A[i - 1] > 0 ? somaSlice[i - 1] + A[i - 1] : 0;
			} else {
				somaSlice[i] = soma[i - 1];
			}
			if (soma[i] > 0) {
				for (int j = 0; j < 3; j++) {
					if (menores[j] < 0) {
						somaSlice[i] -= menores[j];
					}
				}
				if (menores[0] > 0) {
					somaSlice[i] -= menores[0];
				}
			}
			
			somaSlice[i] = somaSlice[i] > 0 ? somaSlice[i] : 0;
			max = max > somaSlice[i] ? max : somaSlice[i];
			
//			System.out.printf("%s = A\n", Arrays.toString(A));
//			System.out.printf("%s = menores\n", Arrays.toString(menores));
//			System.out.printf("%s = soma\n", Arrays.toString(soma));
//			System.out.printf("%s = somaSlice\n", Arrays.toString(somaSlice));
//			System.out.printf("%d = max, %d = i\n", max, i);
//			System.out.println();
		}
		
		return (int) max;
	}
}
