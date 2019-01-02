package codility.com.lessons.l03timecomplexity;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l03timecomplexity.FrogJmp;

public class FrogJmpTest {

	@Test
	public void testSolution() {
		FrogJmp teste = new FrogJmp();
		Assert.assertEquals(teste.solution(10, 85, 30), 3);
	}

}
