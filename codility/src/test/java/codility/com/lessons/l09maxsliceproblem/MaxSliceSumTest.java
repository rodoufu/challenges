package codility.com.lessons.l09maxsliceproblem;

import org.junit.Assert;
import org.junit.Test;

public class MaxSliceSumTest {

	@Test
	public void testSolution() {
		final MaxSliceSum teste = new MaxSliceSum();
		Assert.assertEquals(3, teste.solution(new int[] { 3 }));
		Assert.assertEquals(-10, teste.solution(new int[] { -10 }));
		Assert.assertEquals(-10, teste.solution(new int[] { -10, -15 }));
		Assert.assertEquals(5, teste.solution(new int[] { 3, 2, -6, 4, 0 }));
	}

}
