package codility.com.lessons.l12euclideanalgorithm;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l12euclideanalgorithm.ChocolatesByNumbers;

public class ChocolatesByNumbersTest {

	@Test
	public void testSolution() {
		ChocolatesByNumbers teste = new ChocolatesByNumbers();
		Assert.assertEquals(teste.solution(10, 4), 5);
	}

}
