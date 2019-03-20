package codility.com.lessons.l07stackandqueue;

import java.util.Stack;

/**
 * 100%
 * https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
 */
public class Nesting {
	public int solution(String S) {
		Stack<Boolean> pilha = new Stack<>();
		char[] charArray = S.toCharArray();
		for (char x : charArray) {
			if (x == '(') {
				pilha.push(true);
			} else {
				if (pilha.isEmpty()) {
					return 0;
				}
				pilha.pop();
			}
		}
		return pilha.isEmpty() ? 1 : 0;
	}
}
