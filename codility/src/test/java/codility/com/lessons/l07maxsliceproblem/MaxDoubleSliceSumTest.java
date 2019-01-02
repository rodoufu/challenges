package codility.com.lessons.l07maxsliceproblem;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l09maxsliceproblem.MaxDoubleSliceSum;

public class MaxDoubleSliceSumTest {

	@Test
	public void testSolution() {
		MaxDoubleSliceSum teste = new MaxDoubleSliceSum();
		Assert.assertEquals(teste.solution(new int[] { -2, -3, -4, 1, -5, -6, -7 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 3, 2, 6, -1, 4, 5, -1, 3 }), 17);
		Assert.assertEquals(teste.solution(new int[] { 3, 2, 6 }), 0);
		Assert.assertEquals(teste.solution(new int[] { -8, 10, 20, -5, -7, -4 }), 30);
	}

}
