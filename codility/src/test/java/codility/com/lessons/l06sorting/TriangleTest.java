package codility.com.lessons.l06sorting;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l06sorting.Triangle;

public class TriangleTest {

	@Test
	public void testSolution() {
		Triangle teste = new Triangle();
		Assert.assertEquals(teste.solution(new int[] { 10, 2, 5, 1, 8, 20 }), 1);
	}

}
