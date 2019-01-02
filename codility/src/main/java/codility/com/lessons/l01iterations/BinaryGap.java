package codility.com.lessons.l01iterations;

/**
 * https://codility.com/programmers/lessons/1/
 * 100%
 * @author 08115341622
 */
public class BinaryGap {
	public int solution(int N) {
		int max = 0;

		int digit = N % 2;
		while (digit != 1 && N > 0) {
			N /= 2;
			digit = N % 2;
		}

		int contador = 0;
		while (N > 0) {
			digit = N % 2;
			N /= 2;
			if (digit == 1) {
				max = max > contador ? max : contador;
				contador = 0;
			} else {
				contador++;
			}
		}

		return max;
	}
}
