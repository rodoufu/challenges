package codility.com.lessons.l02arrays;

import org.junit.Assert;
import org.junit.Test;

public class CyclicRotationTest {
	@Test
	public void testSolution() {
		CyclicRotation teste = new CyclicRotation();

		Assert.assertArrayEquals(new int[] { 9, 7, 6, 3, 8 }, teste.solution(new int[] { 3, 8, 9, 7, 6 }, 3));

		Assert.assertArrayEquals(new int[] {}, teste.solution(new int[] {}, 0));
		Assert.assertArrayEquals(new int[] {}, teste.solution(new int[] {}, 1));

		Assert.assertArrayEquals(new int[] { 3, 8, 9, 7, 6 }, teste.solution(new int[] { 3, 8, 9, 7, 6 }, 0));
		Assert.assertArrayEquals(new int[] { 3, 8, 9, 7, 6 }, teste.solution(new int[] { 3, 8, 9, 7, 6 }, 5));

		Assert.assertArrayEquals(new int[] { 6, 3, 8, 9, 7 }, teste.solution(new int[] { 3, 8, 9, 7, 6 }, 1));
		Assert.assertArrayEquals(new int[] { 7, 6, 3, 8, 9 }, teste.solution(new int[] { 3, 8, 9, 7, 6 }, 2));
		Assert.assertArrayEquals(new int[] { 9, 7, 6, 3, 8 }, teste.solution(new int[] { 3, 8, 9, 7, 6 }, 3));
		
		
		Assert.assertArrayEquals(new int[] { 4, 1, 2, 3 }, teste.solution(new int[] { 1, 2, 3, 4 }, 1));
		Assert.assertArrayEquals(new int[] { 3, 4, 1, 2 }, teste.solution(new int[] { 1, 2, 3, 4 }, 2));
		Assert.assertArrayEquals(new int[] { 2, 3, 4, 1 }, teste.solution(new int[] { 1, 2, 3, 4 }, 3));

		Assert.assertArrayEquals(new int[] { -1000, 5 }, teste.solution(new int[] { 5, -1000 }, 1));
		Assert.assertArrayEquals(new int[] { 5, -1000 }, teste.solution(new int[] { 5, -1000 }, 2));

		Assert.assertArrayEquals(new int[] { 3, 5, 1, 1, 2 }, teste.solution(new int[] { 1, 1, 2, 3, 5 }, 42));
		Assert.assertArrayEquals(new int[] { 2, 3, 5, 1, 1 }, teste.solution(new int[] { 1, 1, 2, 3, 5 }, 43));
	}
}
