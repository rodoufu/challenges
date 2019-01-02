package codility.com.lessons.l07stackandqueue;

import java.util.Stack;

/**
 * 100%
 * @author 08115341622
 */
public class Brackets {
	public int solution(String S) {
		Stack<Character> pilha = new Stack<>();
		char[] charArray = S.toCharArray();
		for (char x : charArray) {
			if (x == '(' || x == '{' || x == '[') {
				pilha.push(x);
			} else {
				if (pilha.isEmpty()) {
					return 0;
				}
				switch (pilha.pop().charValue()) {
					case '(':
						if (x != ')') {
							return 0;
						}
						break;
					case '[':
						if (x != ']') {
							return 0;
						}
						break;
					case '{':
						if (x != '}') {
							return 0;
						}
						break;
				}
			}
		}
		return pilha.isEmpty() ? 1 : 0;
	}
}
