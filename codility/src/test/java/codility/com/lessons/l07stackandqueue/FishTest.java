package codility.com.lessons.l07stackandqueue;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l07stackandqueue.Fish;

public class FishTest {

	@Test
	public void testSolution() {
		Fish teste = new Fish();
		Assert.assertEquals(teste.solution(new int[] { 4, 3, 2, 1, 5 }, new int[] { 0, 1, 0, 0, 0 }), 2);
	}

}
