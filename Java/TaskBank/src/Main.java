import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = (n / 10) % 10;
        int y = n % 10;
        System.out.println(x ^ y);
    }
}

