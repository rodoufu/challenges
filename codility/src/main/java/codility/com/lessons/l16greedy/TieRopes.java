package codility.com.lessons.l16greedy;

/**
 * 100%
 * https://app.codility.com/programmers/lessons/16-greedy_algorithms/tie_ropes/
 */
public class TieRopes {
	public int solution(int K, int[] A) {
		int cont = 0;
        for (int i = 0; i < A.length - 1; i++) {
        	if (A[i] >= K) {
        		cont++;
        	} else {
        		A[i + 1] += A[i];
        	}
        }
        if (A[A.length - 1] >= K) {
    		cont++;
    	}
        return cont;
    }
}
