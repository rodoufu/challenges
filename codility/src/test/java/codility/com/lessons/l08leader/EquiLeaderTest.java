package codility.com.lessons.l08leader;

import org.junit.Assert;
import org.junit.Test;

public class EquiLeaderTest {
	@Test
	public void testSolution() {
		EquiLeader teste = new EquiLeader();
		Assert.assertEquals(teste.solution(new int[] {}), 0);
		Assert.assertEquals(teste.solution(new int[] { 1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 4, 3, 4, 4, 4, 2 }), 2);
	}
}
