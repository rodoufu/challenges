package codility.com.lessons.l03timecomplexity;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l03timecomplexity.TapeEquilibrium;

public class TapeEquilibriumTest {

	@Test
	public void testSolution() {
		TapeEquilibrium teste = new TapeEquilibrium();
		Assert.assertEquals(teste.solution(new int[] { 1, 1 }), 0);
		Assert.assertEquals(teste.solution(new int[] { -10, -20, -30, -40, 100 }), 20);
		Assert.assertEquals(teste.solution(new int[] { -1000, 1000 }), 2000);
		Assert.assertEquals(teste.solution(new int[] { 3, 1, 2, 4, 3 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 2000, 2000 }), 0);
		Assert.assertEquals(teste.solution(new int[] { 0, 2000 }), 0);
		Assert.assertEquals(teste.solution(new int[] { 2000, 0 }), 2000);
	}

}
