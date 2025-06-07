import java.io.*;
import java.util.*;

public class Main {
    static class Edge implements Comparable<Edge> {
        int from;
        int to;
        int weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    static int[] parent;

    static int find(int x) {
        if (parent[x] == x) {
            return parent[x];
        }
        return parent[x] = find(parent[x]);
    }

    static boolean union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        parent[rootY] = rootX;
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for (int i=1;i<=n;i++) {
            parent[i] = i;
        }

        ArrayList<Edge> edges = new ArrayList<>();
        for (int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            edges.add(new Edge(from, to, weight));
        }

        Collections.sort(edges);

        int total = 0;
        int cnt = 0;
        int max = 0;

        for (Edge edge : edges) {
            if (union(edge.from, edge.to)) {
                total += edge.weight;
                cnt++;
                max = Math.max(max, edge.weight);
            }

            if (cnt == n-1) break;
        }

        total -= max;

        System.out.println(total);

        br.close();
    }
}
