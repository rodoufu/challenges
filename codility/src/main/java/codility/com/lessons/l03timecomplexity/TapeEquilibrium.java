package codility.com.lessons.l03timecomplexity;

/**
 * https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
 * 100%
 * @author 08115341622
 */
public class TapeEquilibrium {
	public int solution(int[] A) {
		int n = A.length;
		long contE[] = new long[n + 2];
		long contD[] = new long[n + 2];
		contE[0] = contE[n] = contD[0] = contD[n] = Math.abs(A[0] - A[1]);
		for (int i = 0; i < n; i++) {
			contE[i + 1] = contD[i + 1] = A[i];
		}
		for (int i = 1; i < n; i++) {
			contE[i + 1] += contE[i + 1 - 1];
		}
		for (int i = n - 2; i >= 0; i--) {
			contD[i + 1] += contD[i + 1 + 1];
		}
		long menor = Integer.MAX_VALUE;
		for (int i = 2; i < n; i++) {
			menor = Math.abs(contE[i - 1] - contD[i]) < menor ? Math.abs(contE[i - 1] - contD[i]) : menor;
		}
		//System.out.println(Arrays.toString(contE));
		//System.out.println(Arrays.toString(contD));
		return A.length > 2 ? (int) menor : (int)Math.min(contE[0], contD[0]);
	}
}
