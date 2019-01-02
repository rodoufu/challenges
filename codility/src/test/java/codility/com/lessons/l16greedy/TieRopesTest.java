package codility.com.lessons.l16greedy;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l16greedy.TieRopes;

public class TieRopesTest {
	@Test
	public void testSolution() {
		TieRopes teste = new TieRopes();
		Assert.assertEquals(3, teste.solution(4, new int[] { 1, 2, 3, 4, 1, 1, 3 }));
	}
}
