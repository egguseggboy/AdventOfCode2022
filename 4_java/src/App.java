import java.io.File;
import java.util.Scanner;

public class App {
	public static void main(String[] args) throws Exception {
		Scanner f = new Scanner(new File("4.txt"));
		String s;
		String ranges[], range1[], range2[];
		int count1 = 0, count2 = 0;

		while (f.hasNextLine()) {
			s = f.nextLine();
			ranges = s.split(",");
			
			range1 = ranges[0].split("-");
			range2 = ranges[1].split("-");
			int r1l = Integer.parseInt(range1[0]);
			int r1h = Integer.parseInt(range1[1]);
			int r2l = Integer.parseInt(range2[0]);
			int r2h = Integer.parseInt(range2[1]);

			// part 1
			if ((r1l >= r2l && r1h <= r2h) || (r2l >= r1l && r2h <= r1h))
				count1++;
			// part 2
			if (!(r1h < r2l) && !(r2h < r1l))
				count2++;
		}
		f.close();
		System.out.println(count1 + " " + count2);
	}
}
