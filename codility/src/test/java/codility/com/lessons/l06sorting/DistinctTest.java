package codility.com.lessons.l06sorting;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l06sorting.Distinct;

public class DistinctTest {

	@Test
	public void testSolution() {
		Distinct teste = new Distinct();
		Assert.assertEquals(teste.solution(new int[] { 1, 1, 1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 1, -1, 1 }), 2);
		Assert.assertEquals(teste.solution(new int[] { 2, 1, 1, 2, 3, 1 }), 3);
	}

}
