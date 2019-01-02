package codility.com.lessons.l99future;

/**
 * 100% 
 * @author 08115341622
 */
public class StrSymmetryPoint {
	public int solution(String S) {
		final char[] charArray = S.toCharArray();
		if (charArray.length < 1) {
			return charArray.length - 1;
		}
		if (charArray.length % 2 == 0) {
			return -1;
		}
		for (int i = 0; i < charArray.length / 2; i++) {
			if (charArray[i] != charArray[charArray.length - i - 1]) {
				return -1;
			}
		}
		return charArray.length / 2;
	}
}
