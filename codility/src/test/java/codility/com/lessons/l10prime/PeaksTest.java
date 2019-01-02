package codility.com.lessons.l10prime;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l10prime.Peaks;

public class PeaksTest {

	@Test
	public void testSolution() {
		Peaks teste = new Peaks();
		Assert.assertEquals(teste.solution(new int[] { 1, 1, 2, 1, 1, 2, 1, 1, 2 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 1, 1, 2, 1, 1, 2, 1, 3, 2 }), 3);
		Assert.assertEquals(teste.solution(new int[] { 1, 3, 2, 4, 1, 1 }), 2);
		Assert.assertEquals(teste.solution(new int[] { 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 }), 3);
		Assert.assertEquals(teste.solution(new int[] { 1 }), 0);
		Assert.assertEquals(teste.solution(new int[] { 1, 1, 2, 1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 1, 1, 2, 1, 1, 1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 1, 3, 2, 1, 1, 1 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 1, 3, 2, 4, 1, 1, 1, 1 }), 1);

		Assert.assertEquals(teste.solution(new int[] { 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 }), 3);
		Assert.assertEquals(teste.solution(new int[] { 0, 1, 0, 0, 1, 0, 0, 1, 0 }), 3);
		Assert.assertEquals(teste.solution(new int[] { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }), 1);
		Assert.assertEquals(teste.solution(new int[] { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }), 4);

		Assert.assertEquals(teste.solution(new int[] { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }), 4);

		int[] entrada = new int[10];
		Arrays.setAll(entrada, (i) -> 1);
		Assert.assertEquals(teste.solution(entrada), 0);

		entrada = new int[100000];
		Arrays.setAll(entrada, (i) -> i % 2 == 0 ? 0 : 1);
		Assert.assertEquals(teste.solution(entrada), 25000);
	}
}
