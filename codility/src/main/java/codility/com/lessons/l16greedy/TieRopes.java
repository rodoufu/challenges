package codility.com.lessons.l16greedy;

/**
 * 100%
 * @author 08115341622
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
