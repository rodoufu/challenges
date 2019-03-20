package codility.com.lessons.l99future;

/**
 * 100% 
 * https://app.codility.com/programmers/lessons/99-future_training/tree_height/
 */
public class TreeHeight {
	public int solution(Tree T) {
		if (T == null) {
			return -1;
		}
		return 1 + Math.max(solution(T.l), solution(T.r));
	}

	public static class Tree {
		public int x;
		public Tree l;
		public Tree r;
	}
}
