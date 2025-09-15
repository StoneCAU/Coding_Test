import java.io.*;
import java.util.*;

public class Main {
    static class SegTree {
        int n;
        long[] t;

        SegTree(long[] a) {
            n = a.length - 1;
            t = new long[4 * n];
            build(1, 1, n, a);
        }

        void build(int node, int s, int e, long[] a) {
            if (s == e) {
                t[node] = a[s];
                return;
            }
            int m = (s + e) / 2;
            build(2*node, s, m, a);
            build(2*node+1, m+1,e,a);
            t[node] = t[2*node] + t[2*node+1];
        }

        void update(long idx, long val) {
            update(1, 1, n, idx, val);
        }

        void update(int node, int s, int e, long idx, long val) {
            if (s == e) {
                t[node] = val;
                return;
            }
            int m = (s + e) / 2;
            if (idx <= m) update(2*node, s, m, idx, val);
            else update(2*node+1, m+1, e, idx, val);
            t[node] = t[2*node] + t[2*node+1];
        }

        long query(long l, long r) {
            return query(1, 1, n, l, r);
        }

        long query(int node, int s, int e, long l, long r) {
            if (r < s || e < l) return 0;
            if (l <= s && e <= r) return t[node];
            int m = (s + e) / 2;
            return query(2*node, s, m, l, r) + query(2*node+1, m+1,e,l,r);

        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n,m,k;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        long t[] = new long[n+1];
        for (int i=1;i<=n;++i) {
            st = new StringTokenizer(br.readLine());
            t[i] = Long.parseLong(st.nextToken());
        }

        SegTree segTree = new SegTree(t);

        for (int i=0;i<m+k;++i) {
            st = new StringTokenizer(br.readLine());
            long a,b,c;

            a = Long.parseLong(st.nextToken());
            b = Long.parseLong(st.nextToken());
            c = Long.parseLong(st.nextToken());

            if (a == 1) segTree.update(b, c);
            else if (a == 2) {
                System.out.println(segTree.query(b, c));
            }
        }
    }

}