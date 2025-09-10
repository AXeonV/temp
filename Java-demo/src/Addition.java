import java.util.Scanner;

public class Addition {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int number1 = 1;

		System.out.print("Enter the first integer:");
		int number2 = input.nextInt();

		int sum = 0;
		sum = number1 + number2;
		System.out.printf("Sum is %d", sum);
	}
}
