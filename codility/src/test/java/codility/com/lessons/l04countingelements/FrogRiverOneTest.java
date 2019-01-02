package codility.com.lessons.l04countingelements;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l04countingelements.FrogRiverOne;

public class FrogRiverOneTest {

	@Test
	public void testSolution() {
		FrogRiverOne teste = new FrogRiverOne();
		Assert.assertEquals(teste.solution(1, new int[] { 1 }), 0);
		Assert.assertEquals(teste.solution(5, new int[] { 1, 3, 1, 4, 2, 3, 5, 4 }), 6);
	}

}
