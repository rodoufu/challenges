package codility.com.lessons.l01iterations;

import org.junit.Assert;
import org.junit.Test;

public class BinaryGapTest {
	@Test
	public void testSolution() {
		BinaryGap teste = new BinaryGap();

		Assert.assertEquals(2, teste.solution(9));
		Assert.assertEquals(4, teste.solution(529));
		Assert.assertEquals(1, teste.solution(20));
		Assert.assertEquals(0, teste.solution(15));
	}
}
