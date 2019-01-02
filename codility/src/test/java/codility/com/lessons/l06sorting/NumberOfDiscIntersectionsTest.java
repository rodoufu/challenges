package codility.com.lessons.l06sorting;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l06sorting.NumberOfDiscIntersections;

public class NumberOfDiscIntersectionsTest {

	@Test
	public void testSolution() {
		NumberOfDiscIntersections teste = new NumberOfDiscIntersections();
		Assert.assertEquals(teste.solution(new int[] { 1, 5, 2, 1, 4, 0 }), 1);
	}

}
