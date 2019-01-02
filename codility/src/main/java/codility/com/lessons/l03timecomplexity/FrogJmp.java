package codility.com.lessons.l03timecomplexity;

/**
 * 100%
 * @author 08115341622
 *
 */
public class FrogJmp {
	public int solution(int X, int Y, int D) {
		return (Y - X) / D + ((Y - X) % D == 0 ? 0 : 1);
	}
}
