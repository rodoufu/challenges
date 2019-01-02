package codility.com.lessons.l05prefixsums;

/**
 * 100%
 * @author 08115341622
 */
public class PassingCars {
	public int solution(int[] A) {
        long contUm[] = new long[A.length];
        contUm[A.length - 1] = A[A.length - 1] == 1 ? 1 : 0;
        for (int i = A.length - 2; i >= 0; i--) {
        	contUm[i] = contUm[i + 1] +  (A[i] == 1 ? 1 : 0);
        }
        long contador = 0;
        for (int i = 0; i < A.length; i++) {
        	if (A[i] == 0) {
        		if (1000000000 - contador < contUm[i]) {
        			contador = -1;
        			break;
        		}
        		contador += contUm[i];
        	}
        }
        return (int)contador;
    }
}
