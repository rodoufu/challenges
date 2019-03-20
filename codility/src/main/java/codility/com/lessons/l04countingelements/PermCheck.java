package codility.com.lessons.l04countingelements;

/**
 * https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
 * 100%
 * @author 08115341622
 */
public class PermCheck {
	public int solution(int[] A) {
        boolean encontrado[] = new boolean[A.length];
        for (int i = 0; i < A.length; i++) {
        	encontrado[i] = false;
        }
        for (int i = 0; i < A.length; i++) {
        	if (A[i] > A.length) {
        		return 0;
        	}
        	encontrado[A[i] - 1] = true;
        }
        boolean isPermutation = true;
        for (int i = 0; i < A.length && isPermutation; i++) {
        	isPermutation = encontrado[i];
        }
        return isPermutation ? 1 : 0;
    }
}
