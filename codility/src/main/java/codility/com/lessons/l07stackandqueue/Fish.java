package codility.com.lessons.l07stackandqueue;

import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * 100 + 50
 * https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
 */
public class Fish {
	public int solution(int[] A, int[] B) {
		List<Integer> peixes = new LinkedList<>();
		List<Integer> direcoes = new LinkedList<>();
		for (int i = 0; i < A.length; i++) {
			peixes.add(A[i]);
			direcoes.add(B[i]);
		}

		List<Integer> dirs = Arrays.asList(1, 0) ;
		for (int cont = 0; cont < 2; cont++) {
			while (true) {
				//System.out.printf("p: %s\n", peixes);
				//System.out.printf("d: %s\n", direcoes);
				boolean remover = false;
				int dirValue, dirValueNext;
				int peixeValue = 0, peixeValueNext = 0;
				Iterator<Integer> dirIt = direcoes.iterator();
				Iterator<Integer> dirNextIt = direcoes.iterator();
				Iterator<Integer> peixeIt = peixes.iterator();
				Iterator<Integer> peixeNextIt = peixes.iterator();
				dirNextIt.next();
				peixeNextIt.next();
				while (dirNextIt.hasNext()) {
					dirValue = dirIt.next();
					dirValueNext = dirNextIt.next();
					peixeValue = peixeIt.next();
					peixeValueNext = peixeNextIt.next();
					if (dirValue == dirs.get(0) && dirValueNext == dirs.get(1)) {
						remover = true;
						break;
					}
				}
				if (!remover) {
					break;
				}
				if (peixeValue < peixeValueNext) {
					peixeIt.remove();
					dirIt.remove();
				} else {
					peixeNextIt.remove();
					dirNextIt.remove();
				}
			}
			Collections.reverse(peixes);
			Collections.reverse(direcoes);
			Collections.reverse(dirs);
		}

		return peixes.size();
	}
}
