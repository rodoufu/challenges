package codility.com.lessons.l08leader;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l08leader.Dominator;

public class DominatorTest {

	@Test
	public void testSolution() {
		Dominator teste = new Dominator();
		Assert.assertEquals(teste.solution(new int[] { 3, 4, 3, 2, 3, -1, 3, 3 }), 0);
		Assert.assertEquals(teste.solution(new int[] { }), 0);
	}

}
