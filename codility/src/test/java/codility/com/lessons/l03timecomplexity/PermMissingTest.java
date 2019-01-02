package codility.com.lessons.l03timecomplexity;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l03timecomplexity.PermMissingElem;

public class PermMissingTest {

	@Test
	public void testSolution() {
		PermMissingElem teste = new PermMissingElem();
		Assert.assertEquals(teste.solution(new int[] { 2, 3, 1, 5 }), 4);
		Assert.assertEquals(teste.solution(new int[] { }), 0);
		Assert.assertEquals(teste.solution(new int[] { 1 }), 0);
	}

}
