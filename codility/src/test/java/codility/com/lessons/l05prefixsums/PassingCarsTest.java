package codility.com.lessons.l05prefixsums;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l05prefixsums.PassingCars;

public class PassingCarsTest {

	@Test
	public void testSolution() {
		PassingCars teste = new PassingCars();
		Assert.assertEquals(teste.solution(new int[] { 1 }), 0);
		Assert.assertEquals(teste.solution(new int[] { 0, 1, 0, 1, 1 }), 5);
	}

}
