package codility.com.lessons.l90prime2016challenge;

import org.junit.Assert;
import org.junit.Test;

public class DwarfsRaftingTest {
	@Test
	public void testSolution() {
		final DwarfsRafting teste = new DwarfsRafting();
		Assert.assertEquals(6, teste.solution(4, "1B 1C 4B 1D 2A", "3B 2D"));
		Assert.assertEquals(-1, teste.solution(2, "1B", "2A"));
		Assert.assertEquals(3, teste.solution(2, "", "2A"));
		Assert.assertEquals(2, teste.solution(2, "", "2A 1A"));
		Assert.assertEquals(4, teste.solution(2, "", ""));

		Assert.assertEquals(2, teste.solution(2, "2A", ""));
	}
}
