package codility.com.lessons.l09maxsliceproblem;

import org.junit.Assert;
import org.junit.Test;

public class MaxProfitTest {

	@Test
	public void testSolution() {
		final MaxProfit teste = new MaxProfit();
		Assert.assertEquals(0, teste.solution(new int[] { 0 }));
		Assert.assertEquals(0, teste.solution(new int[] { 23171, 23171 }));
		Assert.assertEquals(0, teste.solution(new int[] { 23171, 23170 }));
		Assert.assertEquals(1, teste.solution(new int[] { 23171, 23172 }));

		Assert.assertEquals(356, teste.solution(new int[] { 23171, 21011, 21123, 21366, 21013, 21367 }));
	}

}
