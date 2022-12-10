import java.io.File;
import java.util.Scanner;


public class App {
	public static boolean comp(String a, String b) {
		return a.compareTo(b) == 0;
	}

	public static int solution(Scanner s, int part) {
		int sum = 0;

		while (s.hasNextLine()) {
			String line = s.nextLine();
			String chars[] = line.split(" ");
			if (comp(chars[0], "A")) {
				if (comp(chars[1], "X")) sum += (part == 1) ? (3 + 1) : (0 + 3);
				if (comp(chars[1], "Y")) sum += (part == 1) ? (6 + 2) : (3 + 1);
				if (comp(chars[1], "Z")) sum += (part == 1) ? (0 + 3) : (6 + 2);
			}

			if (comp(chars[0], "B")) {
				if (comp(chars[1], "X")) sum += (part == 1) ? (0 + 1) : (0 + 1);
				if (comp(chars[1], "Y")) sum += (part == 1) ? (3 + 2) : (3 + 2);
				if (comp(chars[1], "Z")) sum += (part == 1) ? (6 + 3) : (6 + 3);
			}

			if (comp(chars[0], "C")) {
				if (comp(chars[1], "X")) sum += (part == 1) ? (6 + 1) : (0 + 2);
				if (comp(chars[1], "Y")) sum += (part == 1) ? (0 + 2) : (3 + 3);
				if (comp(chars[1], "Z")) sum += (part == 1) ? (3 + 3) : (6 + 1);
			}
		}

		return sum;
	}
	public static void main(String[] args) throws Exception {
		File f = new File("2.txt");
		Scanner s1 = new Scanner(f);
		Scanner s2 = new Scanner(f);

		System.out.println(solution(s1, 1) + " " + solution(s2, 2));
		s1.close();
		s2.close();
	}
}
