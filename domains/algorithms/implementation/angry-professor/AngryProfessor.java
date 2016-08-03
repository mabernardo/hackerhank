/*
 * AngryProfessor.java
 * https://www.hackerrank.com/challenges/angry-professor
 *
 * Solution by mabernardo
 * https://github.com/mabernardo
 * https://www.hackerrank.com/mabernardo
 *
 */
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AngryProfessor {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int tests = scan.nextInt();
		
		while (tests-- > 0) {
			int students = scan.nextInt();
			int threshold = scan.nextInt();
			
			List<Integer> arrivals = new ArrayList<>();
			while (students-- > 0) {
				Integer a = scan.nextInt();
				arrivals.add(a);
			}
			
			if (hasCancelled(arrivals, threshold)) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
		scan.close();
	}
	
	private static boolean hasCancelled(List<Integer> list, int threshold) {
		int ontime = 0;
		for (Integer i : list) {
			if (i <= 0) {
				++ontime;
			}
		}
		return ontime < threshold;
	}
}
