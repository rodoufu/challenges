package codility.com.lessons.l06sorting;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l06sorting.MaxProductOfThree;

public class MaxProductOfThreeTest {

	@Test
	public void testSolution() {
		MaxProductOfThree teste = new MaxProductOfThree();
		Assert.assertEquals(teste.solution(new int[] { 1, 1, 1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 1, -1, 1 }), -1);
		Assert.assertEquals(teste.solution(new int[] { -3, 1, 2, -2, 5, 6 }), 60);
		Assert.assertEquals(teste.solution(new int[] { -5, 5, -5, 4 }), 125);
	}

}
