package codility.com.lessons.l07stackandqueue;

import java.util.Stack;

/**
 * 7%
 * @author 08115341622
 */
public class StoneWall {
	public int solution(int[] H) {
		int cont = 0;
		Stack<Integer> alturas = new Stack<>();
		boolean descendo = false;
		for (int i = 1; i < H.length; i++) {
			if (H[i - 1] < H[i]) {
				descendo = false;
				alturas.push(H[i]);
			} else if (H[i - 1] > H[i]) {
				descendo = true;
				cont++;
			}
			
			if (descendo) {
				while(!alturas.empty() && H[i] < alturas.peek()){
					alturas.pop();
                    cont++;
                }
			}
		}
        return cont + alturas.size();
    }
}
