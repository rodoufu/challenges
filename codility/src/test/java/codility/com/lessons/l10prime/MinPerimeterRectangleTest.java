package codility.com.lessons.l10prime;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l10prime.MinPerimeterRectangle;

public class MinPerimeterRectangleTest {

	@Test
	public void testSolution() {
		MinPerimeterRectangle teste = new MinPerimeterRectangle();
		Assert.assertEquals(teste.solution(1), 4);
		Assert.assertEquals(teste.solution(30), 22);
	}

}
