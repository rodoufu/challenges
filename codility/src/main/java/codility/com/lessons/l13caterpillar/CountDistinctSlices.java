package codility.com.lessons.l13caterpillar;

import java.util.HashSet;
import java.util.Set;

/**
 * Not solved
 * https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/
 */
public class CountDistinctSlices {
	public int solution(int M, int[] A) {
		//boolean usado[] = new boolean[M + 1];
		Set<Integer> usado = new HashSet<Integer>();
		int inicio, fim;
		int cont = 0;
		final int max = 1000000000;
		for (inicio = 0; inicio < A.length && cont < max; inicio++) {
			for (fim = inicio; fim < A.length && usado.add(A[fim]); fim++) {
				cont++;
			}
			usado.clear();
//			usado = new boolean[M + 1];
			// usado[A[inicio]] = false;
		}
		return Math.min(cont, max) ;
	}
}
