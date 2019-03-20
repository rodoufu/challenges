package codility.com.lessons.l03timecomplexity;

/**
 * https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
 * 100%
 * @author 08115341622
 *
 */
public class FrogJmp {
	public int solution(int X, int Y, int D) {
		return (Y - X) / D + ((Y - X) % D == 0 ? 0 : 1);
	}
}
