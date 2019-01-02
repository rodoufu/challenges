package codility.com.lessons.l04countingelements;

/**
 * 100%
 * @author 08115341622
 */
public class FrogRiverOne {
	public int solution(int X, int[] A) {
		int time[] = new int[X + 1];
		for (int i = 0; i <= X; i++) {
			time[i] = -1;
		}
		for (int i = A.length - 1; i >= 0; i--) {
			time[A[i]] = i;
		}
		int resposta = -1;
		for (int i = 1; i <= X; i++) {
			resposta = resposta > time[i] ? resposta : time[i];
			if (time[i] == -1) {
				resposta = -1;
				break;
			}
		}
		
		return resposta;
    }
}
