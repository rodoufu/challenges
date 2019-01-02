package codility.com.lessons.l99future;

import org.junit.Assert;
import org.junit.Test;

public class StrSymmetryPointTest {
	@Test
	public void testSolution() {
		StrSymmetryPoint teste = new StrSymmetryPoint();
		Assert.assertEquals(3, teste.solution("racecar"));
		Assert.assertEquals(0, teste.solution("x"));
		Assert.assertEquals(-1, teste.solution(""));
	}
}
