import java.io.File;
import java.util.Scanner;

public class App {
	static int dirsize = 47048086; // hardcoded in cause im lame :(
	static int min = dirsize;
	static int total = 0;

	public static int calc(Scanner scnr, String dir, int sum, int part) {
		String str;
		while (scnr.hasNextLine()) {
			str = scnr.nextLine();
			String tokens[] = str.split(" ");

			if (tokens[0].compareTo("$") == 0) {
				if (tokens[1].compareTo("cd") == 0) {
					if (tokens[2].compareTo("..") == 0) {
						if (part == 1) {
							if (sum <= 100000) {
								total += sum;
								System.out.println("size: " + sum + ", total: " + total);
							}
						} else if (part == 2) {
							if (dirsize - sum <= 40000000 && sum < min) {
								min = sum;
								System.out.println("min: " + min);
							}
						}
						return sum;
					} else {
						if (tokens[2].compareTo("/") != 0) {
							sum += calc(scnr, dir.concat("/" + tokens[2]), 0, part);
						}
					}
				}
			} else {
				try {
					sum += Integer.parseInt(tokens[0]);
				} catch (Exception e) {}
			}
		}
		return sum;
	}
	public static void main(String[] args) throws Exception {
		Scanner s1 = new Scanner(new File("7.txt"));
		Scanner s2 = new Scanner(new File("7.txt"));

		calc(s1, "", 0, 1);
		calc(s2, "", 0, 2);

		s1.close();
		s2.close();
	}
}
