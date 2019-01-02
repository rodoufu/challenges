package codility.com.lessons.l08leader;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class EquiLeader {
	public static class Leader {
		public int value;
		public int cont;

		public Leader(int value, int cont) {
			this.value = value;
			this.cont = cont;
		}
	}

	public int solution(int[] A) {
		if (A.length < 1) {
			return A.length;
		}

		final Map<Integer, Integer> contagem = new HashMap<Integer, Integer>();
		for (int i = 0; i < A.length; i++) {
			contagem.put(A[i], 0);
		}
		contagem.put(A[0], 1);
		
		Leader esquerda[] = new Leader[A.length];
		Leader direita[] = new Leader[A.length];
		esquerda[0] = new Leader(A[0], 1);
		direita[A.length - 1] = new Leader(A[A.length - 1], 1);
		final List<Integer> stack = new ArrayList<>(A.length);
		stack.add(A[0]);
		for (int i = 1; i < A.length; i++) {
			stack.add(A[i]);
			contagem.put(A[i], contagem.get(A[i]) + 1);
			
			final int size = stack.size();
			if (!stack.get(size - 2).equals(stack.get(size - 1))) {
				stack.remove(size - 1);
				stack.remove(size - 2);
			}
		}

		return -1;
	}
}
