package codility.com.lessons.l04countingelements;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l04countingelements.MissingInteger;

public class MissingIntegerTest {

	@Test
	public void testSolution() {
		MissingInteger teste = new MissingInteger();
		Assert.assertEquals(teste.solution(new int[] { 4, 5, 6, 2 }), 1);
		Assert.assertEquals(teste.solution(new int[] { -1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { -2147483648, 2147483647 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 1, 3, 6, 4, 1, 2 }), 5);
	}

}
