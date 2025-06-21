import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        int sum = 0;
        int idx = 0;

        for (int i = 0;i<s.length();i++) {
            char c = s.charAt(i);

            if (!Character.isDigit(c)) {
                idx = i;
                continue;
            }
            if (i % 2 == 0) sum += Integer.parseInt(String.valueOf(c));
            else sum += 3 * Integer.parseInt(String.valueOf(c));
        }

        for (int i = 0; i <= 9; i++) {
            int totalSum;

            if (idx % 2 == 0) {
                totalSum = sum + i;      // * 위치가 짝수면 가중치 1
            } else {
                totalSum = sum + i * 3;  // * 위치가 홀수면 가중치 3
            }

            if (totalSum % 10 == 0) {
                System.out.println(i);
                break;
            }
        }
    }
}
