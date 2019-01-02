package codility.com.lessons.l99future;

import org.junit.Assert;
import org.junit.Test;

public class TreeHeightTest {
	@Test
	public void testSolution() {
		TreeHeight teste = new TreeHeight();
		final TreeHeight.Tree three = new TreeHeight.Tree();
		Assert.assertEquals(0, teste.solution(three));
		
		three.l = new TreeHeight.Tree();
		Assert.assertEquals(1, teste.solution(three));
		three.r = new TreeHeight.Tree();
		Assert.assertEquals(1, teste.solution(three));

		three.r.r = new TreeHeight.Tree();
		Assert.assertEquals(2, teste.solution(three));
	}
}
