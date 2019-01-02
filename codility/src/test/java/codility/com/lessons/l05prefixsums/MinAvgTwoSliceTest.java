package codility.com.lessons.l05prefixsums;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l05prefixsums.MinAvgTwoSlice;

public class MinAvgTwoSliceTest {

	@Test
	public void testSolution() {
		MinAvgTwoSlice teste = new MinAvgTwoSlice();
		Assert.assertEquals(teste.solution(new int[] { 4, 2, 2, 5, 1, 5, 8 }), 1);
	}

}
