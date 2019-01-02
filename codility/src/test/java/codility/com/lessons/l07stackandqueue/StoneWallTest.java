package codility.com.lessons.l07stackandqueue;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l07stackandqueue.StoneWall;

public class StoneWallTest {

	@Test
	public void testSolution() {
		StoneWall teste = new StoneWall();
		Assert.assertEquals(teste.solution(new int[] { 8, 8, 5, 7, 9, 8, 7, 4, 8 }), 7);
	}

}
