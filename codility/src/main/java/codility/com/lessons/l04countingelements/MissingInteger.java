package codility.com.lessons.l04countingelements;

import java.util.Collection;
import java.util.HashSet;

/**
 * 100%
 * @author 08115341622
 */
public class MissingInteger {
	public int solution(int[] A) {
		Collection<Integer> numeros = new HashSet<Integer>();
		for (int x : A) {
			numeros.add(x);
		}
		int min = 1;
		while (numeros.contains(min)) {
			min++;
		}
		return min;
	}
}
