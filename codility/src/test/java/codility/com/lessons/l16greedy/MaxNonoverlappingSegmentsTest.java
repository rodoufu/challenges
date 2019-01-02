package codility.com.lessons.l16greedy;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l16greedy.MaxNonoverlappingSegments;

public class MaxNonoverlappingSegmentsTest {
	@Test
	public void testSolution() {
		MaxNonoverlappingSegments teste = new MaxNonoverlappingSegments();
		Assert.assertEquals(3, teste.solution(new int[] { 1, 3, 7, 9, 9 }, new int[] { 5, 6, 8, 9, 10 }));
	}
}
