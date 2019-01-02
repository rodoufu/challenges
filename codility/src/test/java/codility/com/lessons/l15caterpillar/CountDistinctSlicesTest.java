package codility.com.lessons.l15caterpillar;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l13caterpillar.CountDistinctSlices;

public class CountDistinctSlicesTest {

	@Test
	public void testSolution() {
		CountDistinctSlices teste = new CountDistinctSlices();
		Assert.assertEquals(9, teste.solution(6, new int[] { 3, 4, 5, 5, 2 }));
		Assert.assertEquals(7, teste.solution(3, new int[] { 1, 2, 3, 3 }));
	}

}
