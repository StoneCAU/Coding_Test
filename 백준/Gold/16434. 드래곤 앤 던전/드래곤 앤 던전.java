import java.io.*;
import java.util.*;

public class Main {

    static class RoomInfo {
        long t;
        long a;
        long h;

        RoomInfo(long t, long a, long h) {
            this.t = t;
            this.a = a;
            this.h = h;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long ATK = Long.parseLong(st.nextToken());

        RoomInfo[] room = new RoomInfo[(int) (n+1)];

        for (int i=1;i<=n;i++) {
            st = new StringTokenizer(br.readLine());
            long t = Long.parseLong(st.nextToken());
            long a = Long.parseLong(st.nextToken());
            long h = Long.parseLong(st.nextToken());

            room[i] = new RoomInfo(t,a,h);
        }

        long left = 1;
        long right = Long.MAX_VALUE;
        long answer = right;

        while (left <= right) {
            long mid = (left + right) / 2;
            long hp = mid;
            long atk = ATK;
            boolean survived = true;

            for (int i = 1; i <= n; i++) {
                long t = room[i].t;
                long a = room[i].a;
                long h = room[i].h;

                if (t == 1) {
                    long turns = (h + atk - 1) / atk;
                    hp -= (turns - 1) * a;
                    if (hp <= 0) {
                        survived = false;
                        break;
                    }
                } else {
                    atk += a;
                    hp = Math.min(hp + h, mid);
                }
            }

            if (survived) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        bw.write(String.valueOf(answer));
        bw.flush();
    }
}