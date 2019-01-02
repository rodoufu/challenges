package codility.com.lessons.l05prefixsums;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l05prefixsums.CountDiv;

public class CountDivTest {

	@Test
	public void testSolution() {
		CountDiv teste = new CountDiv();
		Assert.assertEquals(teste.solution(6, 11, 2), 3);
		Assert.assertEquals(teste.solution(11, 19, 10), 0);
		Assert.assertEquals(teste.solution(9, 11, 10), 1);
		Assert.assertEquals(teste.solution(0, 0, 11), 1);
		Assert.assertEquals(teste.solution(11, 345, 17), 20);
		Assert.assertEquals(teste.solution(10, 10, 7), 0);
		Assert.assertEquals(teste.solution(0, 14, 2), 8);
		Assert.assertEquals(teste.solution(11, 13, 2), 1);
	}

}
