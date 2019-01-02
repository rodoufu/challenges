package codility.com.lessons.l07stackandqueue;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l07stackandqueue.Nesting;

public class NestingTest {

	@Test
	public void testSolution() {
		Nesting teste = new Nesting();
		Assert.assertEquals(teste.solution("(()(())())"), 1);
		Assert.assertEquals(teste.solution("())"), 0);
	}

}
