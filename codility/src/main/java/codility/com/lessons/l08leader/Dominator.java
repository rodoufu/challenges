package codility.com.lessons.l08leader;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * 100
 * https://app.codility.com/programmers/lessons/8-leader/dominator/
 */
public class Dominator {
	public int solution(int[] A) {
		Map<Integer, List<Integer>> mapa = new HashMap<>();
		if (A.length == 0) {
			return -1;
		}
		int size = 1;
		int maior = A[0];
		{
			LinkedList<Integer> linkedList = new LinkedList<>();
			linkedList.add(0);
			mapa.put(A[0], linkedList);
		}
		for (int i = 1; i < A.length; i++) {
			if (mapa.containsKey(A[i])) {
				List<Integer> list = mapa.get(A[i]);
				list.add(i);
				if (list.size() > size) {
					size = list.size();
					maior = A[i];
				}
			} else {
				LinkedList<Integer> linkedList = new LinkedList<>();
				linkedList.add(i);
				mapa.put(A[i], linkedList);
			}
		}
		return size > A.length / 2.0 ? mapa.get(maior).get(0) : -1;
    }
}
