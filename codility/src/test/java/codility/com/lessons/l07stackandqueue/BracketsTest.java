package codility.com.lessons.l07stackandqueue;

import org.junit.Assert;
import org.junit.Test;

import codility.com.lessons.l07stackandqueue.Brackets;

public class BracketsTest {

	@Test
	public void testSolution() {
		Brackets teste = new Brackets();
		/*
		System.out.println((int) '{');
		System.out.println((int) '}');
		System.out.println((int) '[');
		System.out.println((int) ']');
		System.out.println((int) '(');
		System.out.println((int) ')');
		*/
		Assert.assertEquals(teste.solution("{[()()]}"), 1);
		Assert.assertEquals(teste.solution("([)()]"), 0);
	}

}
