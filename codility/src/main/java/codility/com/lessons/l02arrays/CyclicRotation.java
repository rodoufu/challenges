package codility.com.lessons.l02arrays;

/**
 * https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
 * 100%
 * @author Rodolfo Pereira Araujo
 */
public class CyclicRotation {
	public int[] solution(int[] A, int K) {
		if (K == 0 || A.length == 0) {
			return A;
		}

		K = K % A.length;
		if (K == 0) {
			return A;
		}

		int resposta[] = new int[A.length];
		for (int i = 0; i < A.length; i++) {
			int index = i + K;
			index = index >= A.length ? index - A.length : index;
			resposta[index] = A[i];
		}
		return resposta;
	}

}
