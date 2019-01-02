package codility.com.lessons.l04countingelements;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l04countingelements.MaxCounters;

public class MaxCountersTest {

	@Test
	public void testSolution() {
		MaxCounters teste = new MaxCounters();
		Assert.assertTrue(Arrays.equals(teste.solution(5, new int[] { 3, 4, 4, 6, 1, 4, 4 }), new int[] { 3, 2, 2, 4, 2 }));
		//Assert.assertTrue(Arrays.equals(teste.solution(1, new int[] { 2, 1, 1, 2, 1 }), new int[] { 3, 2, 2, 4, 2 }));
	}

}
