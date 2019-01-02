package codility.com.lessons.l12euclideanalgorithm;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l12euclideanalgorithm.CommonPrimeDivisors;

public class CommonPrimeDivisorsTest {

	@Test
	public void testSolution() {
		CommonPrimeDivisors teste = new CommonPrimeDivisors();
		Assert.assertEquals(1, teste.solution(new int[] { 15, 10, 3 }, new int[] { 75, 30, 5 }));
	}

}
