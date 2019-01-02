package codility.com.lessons.l02arrays;

import org.junit.Assert;
import org.junit.Test;

public class OddOccurrencesInArrayTest {
	@Test
	public void testSolution() {
		OddOccurrencesInArray teste = new OddOccurrencesInArray();

		Assert.assertEquals(7, teste.solution(new int[] { 9, 3, 9, 3, 9, 7, 9 }));
	}
}
