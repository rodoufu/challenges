package codility.com.lessons.l03timecomplexity;

/**
 * 100% 
 * @author 08115341622
 */
public class PermMissingElem {
	public int solution(int[] A) {
		boolean encontrado[] = new boolean[A.length + 2];
		for (int i = 0; i < A.length; i++) {
			encontrado[i] = false;
		}
		for (int i = 0; i < A.length; i++) {
			encontrado[A[i]] = true;
		}
		int resultado = 1;
		for (int i = 1; i <= A.length + 1; i++) {
			if (!encontrado[i]) {
				resultado = i;
				break;
			}
		}
		return resultado;
	}
}
