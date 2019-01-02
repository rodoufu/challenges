package codility.com.lessons.l15caterpillar;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l13caterpillar.AbsDistinct;

public class AbsDistinctTest {

	@Test
	public void testSolution() {
		AbsDistinct teste = new AbsDistinct();
		Assert.assertEquals(5, teste.solution(new int[] { -5, -3, -1, 0, 3, 6 }));
	}

}
