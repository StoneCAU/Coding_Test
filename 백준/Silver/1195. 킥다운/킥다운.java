import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String first = br.readLine();
        String second = br.readLine();;

        if (first.length() < second.length()) {
            String temp = first;
            first = second;
            second = temp;
        }

        int ans = first.length() + second.length();
        // second를 어디서 부터 시작할지?
        for (int i=-second.length();i<first.length();++i) {
            //System.out.println(i);
            boolean hasFour = false;

            // idx가 i부터 겹치기를 해본다
            for (int j=0;j<second.length();++j) {
                int idx = i + j;

                if (idx < 0 || idx >= first.length()) continue;

                if (first.charAt(idx) - '0' + second.charAt(j) - '0' == 4) {
                    hasFour = true;
                    break;
                }
            }

            if (!hasFour) {
                int left = Math.min(0, i);
                int right = Math.max(first.length(), i + second.length());
                ans = Math.min(ans, right - left);
            }
        }

        System.out.println(ans);
    }
}