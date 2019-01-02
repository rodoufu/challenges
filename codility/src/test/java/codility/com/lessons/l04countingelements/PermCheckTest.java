package codility.com.lessons.l04countingelements;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l04countingelements.PermCheck;

public class PermCheckTest {

	@Test
	public void testSolution() {
		PermCheck teste = new PermCheck();
		Assert.assertEquals(teste.solution(new int[] { 1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 4, 1, 3, 2 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 4, 1, 3 }), 0);
	}

}
