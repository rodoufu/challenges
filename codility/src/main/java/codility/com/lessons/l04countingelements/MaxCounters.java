package codility.com.lessons.l04countingelements;

/**
 * 100%
 * @author 08115341622
 */
public class MaxCounters {
	public int[] solution(int N, int[] A) {
		int resp[] = new int[N];
		int max = 0;
		int somar = 0;
		int reiniciou = -1;
		for (int i = 0; i < A.length; i++) {
			int x = A[i];
			if (x == N + 1) {
				reiniciou = i;
				somar += max;
				max = 0;
			} else {
				if (reiniciou != -1) {
					resp = new int[N];
					reiniciou = -1;
				}
				resp[x - 1]++;
				if (max < resp[x - 1]) {
					max = resp[x - 1];
				}
			}
		}
		if (reiniciou != -1) {
			resp = new int[N];
			reiniciou = -1;
		}
		for (int i = 0; i < N; i++) {
			resp[i] += somar;
		}
		return resp;
	}
}
