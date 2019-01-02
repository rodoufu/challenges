package codility.com.lessons.l05prefixsums;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l05prefixsums.GenomicRangeQuery;

public class GenomicRangeQueryTest {

	@Test
	public void testSolution() {
		GenomicRangeQuery teste = new GenomicRangeQuery();
		Assert.assertTrue(Arrays.equals(teste.solution("CAGCCTA", new int[] { 2, 5, 0 }, new int[] { 2, 4, 1 }), new int[] { 4, 5, 6 }));
	}

}
