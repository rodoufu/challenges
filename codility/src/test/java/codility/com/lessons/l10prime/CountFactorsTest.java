package codility.com.lessons.l10prime;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l10prime.CountFactors;

public class CountFactorsTest {

	@Test
	public void testSolution() {
		CountFactors teste = new CountFactors();
//		Assert.assertEquals(teste.solution(1), 1);
//		Assert.assertEquals(teste.solution(24), 8);
//		Assert.assertEquals(teste.solution(Integer.MAX_VALUE), 8);
		Assert.assertEquals(teste.solution(2147395600), 135);
	}

}
