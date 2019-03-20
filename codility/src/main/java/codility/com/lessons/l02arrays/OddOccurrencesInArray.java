package codility.com.lessons.l02arrays;

import java.util.HashSet;
import java.util.Set;

/**
 * https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
 * 100% 
 * @author 08115341622
 */
public class OddOccurrencesInArray {
	public int solution(int[] A) {
		Set<Integer> elementos = new HashSet<>();
		for (int x : A) {
			if (!elementos.remove(x)) {
				elementos.add(x);
			}
		}
		return elementos.iterator().next();
    }
}
